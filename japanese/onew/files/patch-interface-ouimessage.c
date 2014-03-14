--- interface/ouimessage.c.orig	1994-06-04 19:37:36.000000000 +0900
+++ interface/ouimessage.c	2013-11-03 22:34:46.000000000 +0900
@@ -1,12 +1,14 @@
 /*
  *	MESSAGE OUTPUT TO APPLICATION USER INTERFACE
  */
+#include <stdio.h>
+#include <string.h>
+#include <stdarg.h>
+#include "onew.h"
+
 char *Onew_RK_smode();
 char *romkan_help();
 
-typedef char Linebuff[1024];
-typedef char Mssgbuff[1024];
-
 static Linebuff LASTMSG;
 static Linebuff LASTMODE;
 static Linebuff LASTHELP;
@@ -16,8 +18,8 @@
 static int ONEW_msg_overw;
 static int ONEW_msg_retain;
 
-Onew_putmode(mode,help)
-	char *mode,*help;
+void
+Onew_putmode(char *mode, char *help)
 {	int modeflags,xmodef;
 	char xmode[128];
 	char xhelp[512];
@@ -48,21 +50,30 @@
 	}
 }
 
-Onew_putmsg_sys(so,fmt,a,b,c,d,e,f,g)
-	char *fmt,*a,*b,*c,*d,*e,*f,*g;
+void
+Onew_putmsg_sys(int so, char *fmt, ...)
 {
+	va_list list;
+
+	va_start(list, fmt);
 	ONEW_msg_overw = 1;
-	Onew_putmsg(so,fmt,a,b,c,d,e,f,g);
+	Onew_putmsg(so, fmt, list);
+	va_end(list);
 }
-Onew_putmsg_retain(so,fmt,a,b,c,d,e,f,g)
-	char *fmt,*a,*b,*c,*d,*e,*f,*g;
+void
+Onew_putmsg_retain(int so, char *fmt, ...)
 {
+	va_list list;
+
+	va_start(list, fmt);
 	ONEW_msg_retain = 1;
-	Onew_putmsg(so,fmt,a,b,c,d,e,f,g);
+	Onew_putmsg(so, fmt, list);
+	va_end(list);
 }
 
+void
 Onew_putmodef(mode,fmt,a,b,c,d,e,f,g)
-	char *fmt,*a,*b,*c,*d,*e,*f,*g;
+	char *mode,*fmt,*a,*b,*c,*d,*e,*f,*g;
 {	char help[1024];
 
 	sprintf(help,fmt,a,b,c,d,e,f,g);
@@ -71,6 +82,7 @@
 
 static Linebuff PUSHEDMODE;
 static Linebuff PUSHEDHELP;
+void
 Onew_pushmode(mode)
 	char *mode;
 {
@@ -79,25 +91,28 @@
 	strcpy(PUSHEDHELP,LASTHELP);
 	Onew_putmode(mode,"");
 }
+void
 Onew_popmode()
 {
 	ONEW_modedepth--;
 	Onew_putmode(PUSHEDMODE,PUSHEDHELP);
 }
 
+void
 Onew_curmsg(msg)
 	char *msg;
 {
 	strcpy(LASTMSG,msg);
 }
-Onew_putmsg(so,F,a,b,c,d,e,f,g)
-	char *F;
-	char *a,*b,*c,*d,*e,*f,*g;
+void
+Onew_putmsg(int so, char *F, ...)
 {	Mssgbuff tmsg,msg;
 	char *mp;
 	int maxcol = ouiMESSAGE_COLS();
+	va_list list;
 
-	sprintf(tmsg,F,a,b,c,d,e,f,g);
+	va_start(list, F);
+	sprintf(tmsg,F,list);
 
 /*	sprintf(msg,"%s%*s",so?" ":"",-maxcol,tmsg); */
 	sprintf(msg,"%*s",-maxcol,tmsg);
@@ -117,4 +132,5 @@
 		ouiMESSAGE(so,"%s",msg);
 		strcpy(LASTMSG,msg);
 	}
+	va_end(list);
 }
