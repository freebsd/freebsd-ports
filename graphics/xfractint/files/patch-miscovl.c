--- miscovl.c.orig	Mon Apr  8 19:33:28 2002
+++ miscovl.c	Mon Sep  3 16:42:54 2007
@@ -5,13 +5,13 @@
 #include <string.h>
 #include <ctype.h>
 #include <time.h>
+#include <stdarg.h>
 #ifndef XFRACT
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
 #include <process.h>
-#include <stdarg.h>
 #include <io.h>
-#else
-#include <varargs.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
 #include "port.h"
@@ -24,12 +24,7 @@
 static void write_batch_parms(char *colorinf,int colorsonly, int maxcolor,int i, int j);
 static void expand_comments(char far *target, char far *source);
 
-#ifndef XFRACT
 static void put_parm(char *parm,...);
-#else
-static void put_parm();
-extern  int fake_lut;
-#endif
 
 static void put_parm_line(void);
 static int getprec(double,double,double);
@@ -1102,9 +1097,6 @@
          int curc,scanc,force,diffmag = -1;
          int delta,diff1[4][3],diff2[4][3];
          curc = force = 0;
-#ifdef XFRACT
-         if (fake_lut && !truemode) loaddac(); /* stupid kludge JCO 6/23/2001 */
-#endif
          for(;;) {
             /* emit color in rgb 3 char encoded form */
             for (j = 0; j < 3; ++j) {
@@ -1200,24 +1192,12 @@
       }
 }
 
-#ifndef XFRACT
 static void put_parm(char *parm,...)
-#else
-static void put_parm(va_alist)
-va_dcl
-#endif
 {
    char *bufptr;
    va_list args;
 
-#ifndef XFRACT
    va_start(args,parm);
-#else
-   char * parm;
-
-   va_start(args);
-   parm = va_arg(args,char *);
-#endif
    if (*parm == ' '             /* starting a new parm */
      && wbdata->len == 0)       /* skip leading space */
       ++parm;
