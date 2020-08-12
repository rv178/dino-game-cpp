#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
void getup()
{
//Chrome dinosaur game C++ edition
//Made by Rohith Vinod
	textcolor(BLACK); //adds text
	textbackground(15);
	clrscr();
	window(10,2,70,3);
	cprintf("Press X to Exit, Press Space to Jump");
	window(62,2,80,3);
	cprintf("SCORE : ");
	window(58,5,80,25);
//	cprintf("Made By RV");
	window(58,4,80,25);
//	cprintf("Dino game C++ edition");
	window(1,1,80,25);
//	cprintf("V.0.13");
	window(1,25,80,25);
	for(int x=0;x<79;x++)
	cprintf("п");
	textcolor(0);
}

int t,speed=40;
void ds(int jump=0)
{
	static int a=1;

	if(jump==0)
		t=0;
	else if(jump==2)
		t--;
	else t++;
	window(2,15-t,18,25);
	cprintf("                 "); //character
	cprintf("         ммммммм ");
	cprintf("        лллпллллл");
	cprintf("        ллллллллл");
	cprintf("л       ллллллмм ");
	cprintf("ллм   млллллл    ");
	cprintf(" плммллллллллппл ");
	cprintf("  плллллллллп    ");
	cprintf("   пллллллп      ");
	if(jump==1 || jump==2){
	cprintf("   ллп пл        ");
	cprintf("   лм   лм       ");
	}else if(a==1)
	{
	cprintf("   пллпп ппп     "); //jump animation 1
	cprintf("     лм          ");
	a=2;
	}
	else if(a==2)
	{
	cprintf("    плм пл       ");   //jump animation 2
	cprintf("         лм      ");
	a=1;
	}
	cprintf("                ");
	delay(speed);
}
void obj()
{
	static int x=0,scr=0;
	if(x==56 && t<4)
	{
	scr=0;
	speed=40;
	window(36,8,60,9);
	cprintf("Game Over");
	getch();
	window(36,8,60,9);
	cprintf("         ");
	}
	window(74-x,20,80-x,25);
	cprintf(" л   л ");
	cprintf(" л   л ");   //obstacle
	cprintf(" пплпп ");
	cprintf("   л   ");
	cprintf("   л   ");
	x++;
	if(x==73)
	{
	x=0;
	scr++;
	window(70,2,80,3);
	cprintf("     ");
	window(70,2,80,3);
	cprintf("%d",scr);
	if(speed>20)
		speed--;
	}
}
void main()
{
	char ch;
	int i;
	getup();
	while(1){
	while(!kbhit())
	{
		ds();
		obj();
	}
	ch=getch();
	if(ch==' ')
	{
		for(i=0;i<10;i++)
		{
		ds(1);
		obj();
		}
		for(i=0;i<10;i++)
		{
		ds(2);
		obj();
		}
	}
	else if (ch=='x')
	return;
	} //outer while
}