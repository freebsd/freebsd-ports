--- blockade.c.orig	Mon May 24 16:16:10 1999
+++ blockade.c	Fri Aug 29 17:10:26 2003
@@ -10,7 +10,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <sys/time.h>
 #include <ctype.h>
 
@@ -22,7 +22,6 @@
 #include <X11/keysym.h>
 #include <X11/Xresource.h>
 
-char *malloc();
 #define NEW(t) ((t *)malloc(sizeof(t)))
 #define OLD(v) free((char *)(v))
 
@@ -34,8 +33,6 @@
 
 char **argvec;
 
-char *getenv();
-
 XrmDatabase db;
 char *defaults = "\
 *Background: black\n\
@@ -285,15 +282,12 @@
 /********************************************************************/
 /********************************************************************/
 
-void bugchk(va_alist)
-va_dcl
+void bugchk(char *fmt, ...)
 {
  va_list ap;
- char *fmt;
 
  fprintf(stderr,"INTERNAL ERROR: ");
- va_start(ap);
- fmt = va_arg(ap,char *);
+ va_start(ap, fmt);
  vfprintf(stderr,fmt,ap);
  va_end(ap);
  fprintf(stderr,"\n");
@@ -1060,24 +1054,22 @@
  winshadow.font = None; /* ie, the default font */
 }
 
-void setup_gc(va_alist)
-va_dcl
+void setup_gc(long int bit, ...)
 {
  va_list ap;
- long int bit;
  int setdeffont;
  unsigned long int gcmask;
  GC gc;
  XGCValues *shadow;
  XGCValues gcval;
 
- va_start(ap);
+ va_start(ap, bit);
  gc = wingc;
  shadow = &winshadow;
  setdeffont = 0;
  gcmask = 0;
  while (1)
-  { bit = va_arg(ap,long int);
+  { 
     switch (bit)
      { default:
 	  fprintf(stderr,"Bad bit 0x%lx to setup_gc\n",bit);
@@ -1125,6 +1117,7 @@
 	   }
 	  break;
      }
+     bit = va_arg(ap,long int);
   }
 }
 
@@ -2831,14 +2824,11 @@
  XMoveResizeWindow(disp,msgwin,(topw-msg_w)/2,gamey+(gameh-msg_h)/2,msg_w,msg_h);
 }
 
-void popmsg(va_alist)
-va_dcl
+void popmsg(char *fmt, ...)
 {
  va_list ap;
- char *fmt;
 
- va_start(ap);
- fmt = va_arg(ap,char *);
+ va_start(ap, fmt);
  vsprintf(&msg_buf[0],fmt,ap);
  msg_len = strlen(&msg_buf[0]);
  va_end(ap);
