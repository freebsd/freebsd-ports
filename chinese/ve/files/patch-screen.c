--- screen.c.orig	2009-10-06 23:07:16.000000000 +0800
+++ screen.c	2009-10-06 23:15:01.000000000 +0800
@@ -6,7 +6,7 @@
 /* update : 95/12/15                                     */
 /*-------------------------------------------------------*/
 
-#include <varargs.h>
+#include <stdarg.h>
 #include "bbs.h"
 
 extern char clearbuf[];
@@ -46,8 +46,6 @@
 {
   if (!dumb_term && !big_picture)
   {
-    extern char *calloc();
-
     scr_lns = t_lines;
     scr_cols = t_columns = ANSILINELEN;
     /* scr_cols = MIN(t_columns, ANSILINELEN); */
@@ -601,14 +599,13 @@
 
 
 void
-prints(va_alist)
-va_dcl
+prints(char *fmt, ...)
 {
   va_list args;
-  char buff[512], *fmt;
+  char buff[512];
+
+  va_start(args, fmt);
 
-  va_start(args);
-  fmt = va_arg(args, char *);
   vsprintf(buff, fmt, args);
   va_end(args);
   outs(buff);
