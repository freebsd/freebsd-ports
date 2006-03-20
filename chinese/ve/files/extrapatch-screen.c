--- screen.c.orig	Thu Dec 18 01:08:35 2003
+++ screen.c	Thu Dec 18 01:09:44 2003
@@ -6,7 +6,7 @@
 /* update : 95/12/15                                     */
 /*-------------------------------------------------------*/
 
-#include <varargs.h>
+#include <stdarg.h>
 #include "bbs.h"
 
 extern char clearbuf[];
@@ -601,13 +601,12 @@
 
 
 void
-prints(va_alist)
-va_dcl
+prints(char *fmt, ...)
 {
   va_list args;
-  char buff[512], *fmt;
+  char buff[512];
 
-  va_start(args);
+  va_start(args, fmt);
   fmt = va_arg(args, char *);
   vsprintf(buff, fmt, args);
   va_end(args);
