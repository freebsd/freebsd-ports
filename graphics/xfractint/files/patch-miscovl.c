--- miscovl.c.orig	Tue Sep  7 00:38:10 1999
+++ miscovl.c	Sun Dec  7 10:54:31 2003
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
@@ -24,11 +24,7 @@
 static void write_batch_parms(char *colorinf,int colorsonly, int maxcolor,int i, int j);
 static void expand_comments(char far *target, char far *source);
 
-#ifndef XFRACT
 static void put_parm(char *parm,...);
-#else
-static void put_parm();
-#endif
 
 static void put_parm_line(void);
 static int getprec(double,double,double);
@@ -1175,24 +1171,12 @@
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
