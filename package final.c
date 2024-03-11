#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
typedef struct student{char roll[10];
                       char name[25];
                       char course[10];
                       char gender;
                       char dob[11];
                       int age;
                       char d1;
                       char d2;
                       char vacc_name[15];
                       char d1date[11];
                       char d2date[11];
                       char aadhar[13];
                       char phone[11];
                      }student;
struct user{char username[7];
            char password[4];};
void passinput(char p[4])
{
    int i;
    char ch;
    for(i=0;i<4;i++)
        {
            ch=getch();
            if(ch==13)
            {
                break;
            }
            p[i]=ch;
            printf("*");
        }
        p[i]='\0';
        printf("\n");
}
void createpassword()
{
    struct user *u;
    int i,n;
    u=(struct user*)calloc(n,sizeof(struct user));
    FILE *fp;
    fp=fopen("Login.txt","w");
    printf("Enter the no of records:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the username:\t");
        scanf("%s",u[i].username);
        printf("Enter the password:\t");
        scanf("%s",u[i].password);
        fwrite(&u[i],sizeof(struct user),1,fp);
    }

    fclose(fp);
}
void addpassword()
{
    struct user *u;
    int i,n;
    u=(struct user*)calloc(n,sizeof(struct user));
    printf("Enter the no of records:");
    scanf("%d",&n);
    FILE *fp;
    fp=fopen("Login.txt","a");
    for(i=0;i<n;i++)
    {
        printf("Enter the username:");
        scanf("%s",u[i].username);
        printf("Enter the password:");
        scanf("%s",u[i].password);
        fwrite(&u[i],sizeof(struct user),1,fp);
    }
    fclose(fp);
}
void displaypassword()
{
    struct user u1;
    FILE *fp;
    fp=fopen("Login.txt","r");
    printf("USERNAME\tPASSWORD\n");
    while(fread(&u1,sizeof(struct user),1,fp))
    {
        printf("%s\t\t%s\n",u1.username,u1.password);
    }
    fclose(fp);
}
void deletepassword(char ro[7])
{
    struct user u1;
    int found;
    FILE *fp,*fp1;
    fp=fopen("Login.txt","r");
    fp1=fopen("Temp.txt","w");
    while(fread(&u1,sizeof(struct user),1,fp))
    {
        if(strcmp(ro,u1.username)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&u1,sizeof(struct user),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("Login.txt");
    rename("Temp.txt","Login.txt");
}
void create(char usern[7])
{
    FILE *fp1;
    student s;
    fp1=fopen("vaccine.txt","a");
    strcpy(s.roll,usern);
    printf("Enter your name : ");
    scanf(" %[^\n]s",&s.name);
    printf("Enter your course : ");
    scanf("%s",&s.course);
    printf("Enter your sex : ");
    scanf(" %c",&s.gender);
    printf("Enter the name of the vaccine : ");
    scanf(" %s",&s.vacc_name);
    printf("Enter the date of birth : ");
    scanf("%s",&s.dob);
    printf("Enter your age : ");
    scanf("%d",&s.age);
    dd1:
    printf("Have you taken dose-1(y/n) : ");
    scanf(" %c",&s.d1);
    if(s.d1=='y' || s.d1=='Y')
    {
        printf("Enter the date of dose-1(dd/mm/yyyy) : ");
        scanf("%s",&s.d1date);
    }
    else if(s.d1=='n' || s.d1=='N')
    {
        strcpy(s.d1date,"-");
    }
    else
    {
        printf("Invalid input\n");
        Beep(500,250);
        goto dd1;
    }
    dd2:
    printf("Have you taken dose-2(y/n) : ");
    scanf(" %c",&s.d2);
    if(s.d2=='y' || s.d2=='Y')
    {
        printf("Enter the date of dose-1(dd/mm/yyyy) : ");
        scanf("%s",&s.d2date);
    }
    else if(s.d2=='n' || s.d2=='N')
    {
        strcpy(s.d2date,"-");
    }
    else
    {
        printf("Invalid input\n");
        goto dd2;
    }
    a:
    printf("Enter the Aadhar  number : ");
    scanf(" %s",&s.aadhar);
    if(strlen(s.aadhar)!=12)
    {
        printf("Invalid aadhar number\n");
        Beep(500,250);
        goto a;
    }
    m:
    printf("Enter the mobile number : ");
    scanf(" %s",&s.phone);
    if(strlen(s.phone)!=10)
    {
        printf("Invalid mobile number\n");
        Beep(500,250);
        goto m;
    }
    fwrite(&s,sizeof(student),1,fp1);
    fclose(fp1);

}
void view(char usern[7])
{
    student s;
    FILE *fp1;
    int f=0;
    fp1=fopen("vaccine.txt","r");
    printf("\tROLL NUMBER\tNAME\t\tCOURSE\t\tGENDER\t\tVACCINE NAME\t\tDATE OF BIRTH\tAGE\tDOSE-1\t\tDOSE-2\t\tAADHAR NUMBER\tPHONE NUMBER\n");
    while(fread(&s,sizeof(student),1,fp1))
    {
        if(strcmp(s.roll,usern)==0)
        {
            f=1;
              printf("\t%-15s\t%-15s\t%-15s\t%-15c\t%-15s\t\t%-15s\t%d\t%-15s\t%-15s\t%-15s\t%-15s\n\n",s.roll,s.name,s.course,s.gender,s.vacc_name,s.dob,s.age,s.d1date,s.d2date,s.aadhar,s.phone);
        }
    }
    if(!f)
    {
        printf("Record not found\n");
    }
    fclose(fp1);
}
void edit(char usern[7])
{
    student s;
    FILE *fp1,*fp2;
    int f;
    fp1=fopen("vaccine.txt","r");
    fp2=fopen("1.txt","w");
    while(fread(&s,sizeof(student),1,fp1))
        {
            if(strcmp(s.roll,usern)==0)
            {
                f=1;
                fp1=fopen("vaccine.txt","a");
                strcpy(s.roll,usern);
                printf("Enter your name : ");
                scanf(" %[^\n]s",&s.name);
                printf("Enter your course : ");
                scanf("%s",&s.course);
                printf("Enter your sex : ");
                scanf(" %c",&s.gender);
                printf("Enter the name of the vaccine : ");
                scanf("%s",&s.vacc_name);
                printf("Enter the date of birth : ");
                scanf("%s",&s.dob);
                printf("Enter your age : ");
                scanf("%d",&s.age);
                dd1:
                printf("Have you taken dose-1(y/n) : ");
                scanf(" %c",&s.d1);
                if(s.d1=='y' || s.d1=='Y')
                {
                printf("Enter the date of dose-1(dd/mm/yyyy) : ");
                scanf("%s",&s.d1date);
                }
                else if(s.d1=='n' || s.d1=='N')
                {
                    strcpy(s.d1date,"-");
                }
                else
                {
                    printf("Invalid input\n");
                    goto dd1;
                }
                dd2:
                printf("Have you taken dose-2(y/n) : ");
                scanf(" %c",&s.d2);
                if(s.d2=='y' || s.d2=='Y')
                {
                    printf("Enter the date of dose-1(dd/mm/yyyy) : ");
                    scanf("%s",&s.d2date);
                }
                else if(s.d2=='n' || s.d2=='N')
                {
                    strcpy(s.d2date,"-");
                }
                else
                {
                    printf("Invalid input");
                    goto dd2;
                }
                a:
                printf("Enter the Aadhar  number : ");
                scanf(" %s",&s.aadhar);
                if(strlen(s.aadhar)!=12)
                {
                    printf("Invalid aadhar number\n");
                    goto a;
                }
                m:
                printf("Enter the mobile number : ");
                scanf(" %s",&s.phone);
                if(strlen(s.phone)!=10)
                {
                    printf("Invalid mobile number\n");
                    goto m;
                }
            }
            fwrite(&s,sizeof(student),1,fp2);
        }
        fclose(fp1);
        fclose(fp2);
        if(f==1)
        {
            fp2=fopen("1.txt","r");
            fp1=fopen("vaccine.txt","w");
            while(fread(&s,sizeof(student),1,fp2))
            {
                fwrite(&s,sizeof(student),1,fp1);
            }
            fclose(fp1);
            fclose(fp2);
        }
        else
        {
            printf("Record not found\n");
        }
}
void total_no_of_dose1()
{
    student s;
    int n=0;
    FILE *fp;
    fp=fopen("vaccine.txt","r");
    while(fread(&s,sizeof(student),1,fp))
    {
        if(s.d1=='y' || s.d1=='Y')
        {
            n=n+1;
        }
    }
    printf("Total no of people took 1st dose : %d",n);
}
void total_no_of_dose2()
{
    student s;
    int n=0;
    FILE *fp;
    fp=fopen("vaccine.txt","r");
    while(fread(&s,sizeof(student),1,fp))
    {
        if(s.d2=='y' || s.d2=='Y')
        {
            n=n+1;
        }
    }
    printf("Total no of people took 2nd dose : %d",n);
}
void deleterecord()
{
    student s;
    FILE *fp1,*fp2;
    int f;
    char no[7];
    printf("Enter the roll number to be deleted: ");
    scanf("%s",&no);
    fp1=fopen("vaccine.txt","r");
    fp2=fopen("1.txt","w");
    while(fread(&s,sizeof(student),1,fp1))
    {
        if(strcmp(s.roll,no)==0)
        {
            f=1;
        }
        else
        {
            fwrite(&s,sizeof(student),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(f==1)
    {
        fp2=fopen("1.txt","r");
        fp1=fopen("vaccine.txt","w");
        while(fread(&s,sizeof(student),1,fp2))
        {
            fwrite(&s,sizeof(student),1,fp1);
        }
        fclose(fp1);
        fclose(fp2);
    }
    else
    {
        printf("Record not found\n");
    }
    deletepassword(no);
}
void display()
{
    student s;
    FILE *fp1;
    fp1=fopen("vaccine.txt","r");
    printf("\tROLL NUMBER\tNAME\t\tCOURSE\t\tGENDER\t\tVACCINE NAME\t\tDATE OF BIRTH\tAGE\tDOSE-1\t\tDOSE-2\t\tAADHAR NUMBER\tPHONE NUMBER\n");
    while(fread(&s,sizeof(student),1,fp1))
    {
       printf("\t%-15s\t%-15s\t%-15s\t%-15c\t%-15s\t\t%-15s\t%d\t%-15s\t%-15s\t%-15s\t%-15s\n\n",s.roll,s.name,s.course,s.gender,s.vacc_name,s.dob,s.age,s.d1date,s.d2date,s.aadhar,s.phone);
    }
    fclose(fp1);
}
int main()
{
    system("color 0");
    int choice_admin,choice_user,choice_login,chlo;
    char usern[7],passn[4];
    printf("\t\t\t\t\t\t----------WELCOME----------\n");
    printf("\t\t\t\t\t\tVACCINATION MANAGEMENT SYSTEM");
    g1:
    printf("\n1.Login As Admin");
    printf("\n2.Login As User");
    printf("\nEnter your choice:");
    scanf("%d",&choice_login);
    if(choice_login==1)
    {
        printf("\nEnter the username:\t\t");
        scanf("%s",usern);
        printf("Enter the password:\t\t");
        passinput(passn);
        system("cls");
        if(strcmp("admin",usern)==0 && strcmp("hod",passn)==0)
        {
            printf("\nLogin successful");
            printf("\n\n");
            do
            {
                printf("\n");
                printf("1.Create the Username and Password\n");
                printf("2.Add Username and Password\n");
                printf("3.Delete the record\n");
                printf("4.Display all the username and password\n");
                printf("5.Total no of people vaccinated\n");
                printf("6.Display all the records\n");
                printf("7.Exit to login page\n");
                printf("8.Exit from program\n");
                printf("\n");
                printf("Enter the choice:");
                scanf("%d",&choice_admin);
                printf("\n");
                if(choice_admin==1)
                {
                    system("cls");
                    createpassword();
                }
                if(choice_admin==2)
                {
                    system("cls");
                    addpassword();
                }
                if(choice_admin==3)
                {
                    system("cls");
                    deleterecord();
                }
                if(choice_admin==4)
                {
                    system("cls");
                    displaypassword();
                }
                if(choice_admin==5)
                {
                    system("cls");
                    total_no_of_dose1();
                    printf("\n");
                    total_no_of_dose2();
                    printf("\n");
                }
                if(choice_admin==6)
                {
                    system("cls");
                    display();
                }
                if(choice_admin==7)
                {
                    system("cls");
                    goto g1;
                }
            }
            while(choice_admin!=8);
        }
        else
        {
            printf("Invalid Username or Password");
            Beep(800,400);
        }
    }
    if(choice_login==2)
    {
        printf("\nEnter the username:\t\t");
        scanf("%s",usern);
        printf("Enter the password:\t\t");
        passinput(passn);
        system("cls");
        FILE *lp;
        lp=fopen("Login.txt","r");
        struct user u2;
        while(fread(&u2,sizeof(struct user),1,lp))
        {
            if(strcmp(u2.username,usern)==0 && strcmp(u2.password,passn)==0)
            {
                chlo=1;
            }
        }
        if(chlo==1)
        {
            printf("Login Successful");
            printf("\n\n");
            do
            {
                printf("\n");
                printf("1.Add new information\n");
                printf("2.Edit the information\n");
                printf("3.View information\n");
                printf("4.Exit to login page\n");
                printf("\n");
                printf("Enter the choice:");
                scanf("%d",&choice_user);
                if(choice_user==1)
                {
                    system("cls");
                    create(usern);
                }
                if(choice_user==2)
                {
                    system("cls");
                    edit(usern);
                }
                if(choice_user==3)
                {
                    system("cls");
                    view(usern);
                }
                if(choice_user==4)
                {
                    system("cls");
                    goto g1;
                }
            }
            while(choice_user!=0);
        }
        else
        {
            printf("Invalid Username or Password");
            Beep(800,400);
        }

    }
}
