#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int lt,dt,mnt,yer,fog,dc,lpc,yc,d1,d2,l1,l2,r,uk=0,md=0,vv=0;
int b[15]={31,59,90,120,151,181,212,243,273,304,334,365};


void day_count();
void leap_count();
void leap_count2();
void calc();
void unknown();
void print();
void fake_engine();

void main()
{
// clrscr();

 printf("\n enter the year");
 scanf("%d",&yer);
 printf("\n enter the month");
 scanf("%d",&mnt);
 printf("\n enter the date");
 scanf("%d",&dt);
 yc=yer-1;
 day_count();
 leap_count();
 if(yer>=1800)
 leap_count2();
 unknown();
 calc();
 fake_engine();
 print();
 getch();
 }


void day_count()
{if(mnt==1)
 d2=0;
 else
 {d1=mnt-2;
 d2=b[d1];
 }
 dc=d2+dt;
 }


void leap_count()
{l1=yer/4;
if(yer<=1752)
 {if(yer%4==0)
  {if(dc<=60)
   l2=l1-1;
   else
   l2=l1;
  }
  else
  l2=l1;
 }
 else
 {if(yer%100!=0)
  {if(yer%4==0)
   {if(dc<=60)
    l2=l1-1;
    else
    l2=l1;
   }
   else
   l2=l1;
  }
  else
  {if(yer%400==0)
   {if(dc<=60)
    l2=l1-1;
    else
    l2=l1;
   }
   else
   l2=l1-1;
   }
}}

void leap_count2()
{
 int i,j,t1,t2=0,t3,t4=0;
 t1=yc/100;
 for(i=18;i<=t1;i++)
 t2+=1;
 for(j=18;j<=t1;j++)
 {t3=j*100;
 if(t3%400==0)
 t4+=1;
 }
 md=t2-t4;
 //printf("\n t2 %d t4 %d",t2,t4);
}

void unknown()
{if(yer>=2100&&yer<=5900)
 uk=0;

}


void calc()
{if(yer>1752)
 r=3;
 else
 r=0;
 fog=dc+l2+yc+r-md+uk;
 if((mnt==3)&&(dt==1))
 fog+=1;
 lt=fog%7;
}

void fake_engine()
{
int mw=1,fe,re=0,days[20]={31,29,31,30,31,30,31,31,30,31,30,31};
if((dt<=days[mnt-1])&&(mnt<=12)&&(yer>=1))
re=1;
if(yer%4==0)
{if(yer>1752)
 {if(yer%100==0)
  {if(yer%400==0)
  fe=1;
  else
  fe=0;
  }
  else
  fe=1;
 }}
else
fe=0;
if((mnt==2)&&(dt==29))
mw=fe;
if((re==1)&&(mw==1))
vv=1;
//printf("\n\n re %d mw %d fe %d",re,mw,fe);
}


void print()
{
if(vv>=1)
{
printf("\n\n\n");
switch(lt)
{
case 0: printf("friday");break;
case 1: printf("saturday");break;
case 2: printf("sunday");break;
case 3: printf("monday");break;
case 4: printf("tuesday");break;
case 5: printf("wednesday");break;
case 6: printf("thursday");break;
default: printf("error");break;

 } //printf("\n\n\n dc %d l2 %d yc %d l1 %d \n md %d \n",dc,l2,yc,l1,md);
}
else
printf("\n\n INVALID DATA PLEASE RECHECK...........");
}

