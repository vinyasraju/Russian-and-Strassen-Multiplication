#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
struct stack
{
	long int a1[20],a2[20];int top1,top2;
}s;
long int *allocate();
void accept(long int *,long int *);
void multiply(long int *,long int*,struct stack *);
void main()
{
	struct stack *x=&s;
	long int *p,*q;
	int grd,grm;
	detectgraph(&grd,&grm);
	initgraph(&grd,&grm,"");

	p=allocate();
	q=allocate();
	accept(p,q);
	multiply(p,q,x);
	closegraph();
	return;

}
long int *allocate()
{
	long int *a=(long int *)malloc(sizeof(long int));
	return a;
}
void accept(long int *p,long int *q)
{
	int i;
	printf("Enter 2 nos b/w 0 and 999:\n");
	scanf("%ld%ld",&(*p),&(*q));
	if(((*p)>999)||((*q)>999))
	{
		for(i=1;i>0;i++)
		{
			printf("\nRussian multiplication is applicable only for nos b/w 0 and 999.\nSo plz enter no b/w 0 and 999 only:\n");
			printf("\nOr enter -1 to exit:\n");
			scanf("%ld",&(*p));
			if((*p)==-1)
			{
				exit(0);
			}
			else
			{
			scanf("%ld",&(*q));
			if((*p)<=999&&(*q)<=999)
			{
				i=-1;
			}
		}       }
	}
}
void multiply(long int *p,long int *q,struct stack *x)
{
	int i,j,c,v=0,k=0,b=0,r,d=0,a=0,w=0,n=0,y=0,t=0,m=0,g=0,l=0,h=0,z=0,f=250;long int sum=0;
	 int xps,yps,num,xpos,ypos,xp,yp,xs,ys,width=0;
	 char c9[90],c1[90],c2[90],c3[90],c4[90],c5[90],c6[90],s[20],c8[90];

num=getmaxcolor();
xpos=getmaxx()/2;
ypos=getmaxy()/3;
xps=xpos;
yps=ypos;
xs=xpos;
ys=ypos;
setbkcolor(BLUE);
setcolor(YELLOW);
	(*x).top1=-1;
	(*x).top2=-1;
	i=(*x).top1;
	j=(*x).top2;
	if(*p==0||*q==0)
	{
		sum=0;
	}
	else
	{       setcolor(WHITE);
		outtextxy(xpos-30,ypos-30,"Successive Multiplication");
		outtextxy(xpos-15,ypos-15,"    Array");
		outtextxy(xpos-230,ypos-30,"Successive Division");
		outtextxy(xpos-200,ypos-15,"   Array");
		setcolor(YELLOW);
		while(*p>=1)
		{

			i++;
			(*x).a1[i]=*p;
			*p=(*p)/2;

			sprintf(c1,"%ld",(*x).a1[i]);
			outtextxy((xpos/2)-20,ypos+10,c1);
			ypos=ypos+10;

			j++;
			(*x).a2[j]=*q;

			*q=(*q)*2;

			sprintf(c2,"%ld",(*x).a2[j]);

			outtextxy(xpos+10,ypos,c2);
			ypos=ypos+10;




		}

		xpos=getmaxx()/2;
		ypos=getmaxy()/3;
		a=i;
		b=i;
		m=j;
		while((a+1)>=0)
		{
			setcolor(WHITE);
			while(b>=0)
			{

			sprintf(c5,"a[%d]",b);
			b--;
			outtextxy(xs-230,ys+(b*20)+30,c5);
			}
			setcolor(WHITE);
			rectangle(xpos-190,ypos,xpos-120,ypos+v);
			v=v+20;
			a--;

		}
		while((j+1)>=0)
		{
			setcolor(WHITE);
			while(m>=0)
			{	sprintf(c6,"b[%d]",m);
				m--;
				outtextxy(xs-35,ys+(m*20)+30,c6);
			}
			setcolor(WHITE);
			rectangle(xpos,ypos,xpos+70,ypos+g);
			g=g+20;
			j--;

		}
		while(k<=i)
		{
			xp=getmaxx()/2;
			yp=getmaxy()/3;

		      delay(1000);
			if(((*x).a1[k])%2!=0)
		{
			d++;
			xp=getmaxx()/2;
			yp=getmaxy()/3;

			setcolor(BROWN);
			outtextxy(xp+76,yp+(k*20)+10,"Selected");
			setcolor(RED);

			rectangle(xps,yps+((d-1)*20),xps+70,yps+(d*20));
			setcolor(WHITE);

			outtextxy(xp-310,yp+250,"Product=");
			setcolor(YELLOW);
			t=(*x).a2[k];
			h=0;
			while(t!=0)
			{
			h++;
			t=t/10;
			}
			w=w+h;
				if(k==i)
				{
				sprintf(c8,"%ld",(*x).a2[k]);
				n=-f+(w*14);
				outtextxy(xp+n,yp+250,c8);

				}
				else
				{
				sprintf(c3,"%ld+",(*x).a2[k]);
				n=-f+(w*14);
				outtextxy(xp+n,yp+250,c3);

				}
				sum=sum+(*x).a2[k];
				k++;




		}
		else
		{       d++;
			k++;
		}
		}
		xp=getmaxx()/2;
		yp=getmaxy()/3;
		setcolor(BROWN);
		sprintf(c3,"=%ld",sum);
		outtextxy(xp-f-4,yp+260,c3);


	}
	getch();
}
