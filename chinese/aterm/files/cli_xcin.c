/*
	Copyright (C) 1994,1995	Edward Der-Hua Liu, Hsin-Chu, Taiwan
*/

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include "state.h"
#include "protocol.h"

/*static void p_err(char *fmt,...)
{
  va_list args;
  
  va_start(args, fmt);
  fprintf(stderr,"%s:", "cli_xcin:");
  vfprintf(stderr, fmt, args);
  va_end(args);
  fprintf(stderr,"\n");
  exit(-1);
} 
*/


static Atom xcin_atom=0;
static Window xcin_win=None;
static InmdState inmdstate;
#define ENDIAN_TEST() (*(int *)"\x11\x22\x33\x44"==0x11223344)
char my_endian;

static int connect_xcin(Display *display)
{
/*Window twin;*/
xcin_atom=XInternAtom(display, XCIN_ATOM,False);
my_endian=ENDIAN_TEST();  /* if == 11223344, it is big-endian */

xcin_win=XGetSelectionOwner(display,xcin_atom);
return xcin_win;
}

void send_FocusIn(Display *display, Window window)
{
	XClientMessageEvent event;
	/*XEvent erreve;*/
	char *tmp=event.data.b;

	if (connect_xcin(display)==None) return;
/* Ensure xcin exists, or the process will be hanged */
	event.type=ClientMessage;
	event.window=window;
	event.message_type=xcin_atom;
	event.format=8;
	
	tmp[0]=tmp[1]=tmp[2]=0xff;
	tmp[3]=CLI_FOCUS_IN;
	memcpy(&tmp[4],&inmdstate, sizeof(inmdstate));
	XSendEvent(display, xcin_win, False, 0, (XEvent *)&event);
}

void send_FocusOut(Display *display, Window window)
{
	XClientMessageEvent event;
/*	XEvent erreve; */
	char *tmp=event.data.b;

	if (connect_xcin(display)==None) return;
/* Ensure xcin exists, or the process will be hanged */
	event.type=ClientMessage;
	event.window=window;
	event.message_type=xcin_atom;
	event.format=8;
	
	tmp[0]=tmp[1]=tmp[2]=0xff;
	tmp[3]=CLI_FOCUS_OUT;
	memcpy(&tmp[4],&inmdstate, sizeof(inmdstate));
	XSendEvent(display, xcin_win, False, 0, (XEvent *)&event);
}

static void big_little(char *i)
{
char t;
t=*i; *i=*(i+3); *(i+3)=t;
t=*(i+1); *(i+1)=*(i+2); *(i+2)=t;
}
static int read_keys(Display *display, char *buf)
{
	Atom actual_type;
	int actual_format/*,i*/;
	u_long nitems,bytes_after;
	char *ttt, *cp;
	XCIN_RES res;
	int ofs;
 
	cp=(char *)&res;
	ofs=0;
	do { 
	if (XGetWindowProperty(display,xcin_win,xcin_atom,
		ofs/4,(sizeof(XCIN_RES)+3)/4,
		True, AnyPropertyType, &actual_type,&actual_format,
		&nitems,&bytes_after,(unsigned char **)&ttt) != Success)
			puts("err property");
		memcpy((char *)(&res)+(ofs & ~0x3), ttt, nitems);
		XFree(ttt);
		ofs=(ofs & ~0x3) + nitems;
	} while ((!nitems && !ofs) || bytes_after>0);
	if (my_endian) {
		big_little((char *)&res.len);
		big_little((char *)&res.status);
	}
	memcpy(buf,res.tkey, res.len);
	inmdstate=res.inmdstate;
	buf[res.len]=0;
 
	return  res.status;
}

#include <X11/Xutil.h>

static XComposeStatus compose_status = {NULL, 0};

int send_key(Display *display, Window win, XKeyEvent *eve, char *buf)
{
XClientMessageEvent event;
/*XEvent erreve;*/
char *tmp=event.data.b;
u_char tttt[8];
/*KeySym keysym;*/
int count;

if (xcin_win==None && connect_xcin(display)==None)
	return K_REJECT;
if ((xcin_win=XGetSelectionOwner(display,xcin_atom))==None)
	return K_REJECT;

event.type=ClientMessage;
event.window=win;
event.message_type=xcin_atom;
event.format=32;
count = XLookupString (eve, tttt, sizeof(tmp), (KeySym *)tmp, &compose_status);
memcpy(&tmp[4],&eve->state,4);
XSendEvent(display, xcin_win, False, 0, (XEvent *)&event);
XSync(display,False);
return (read_keys(display, buf));
}
