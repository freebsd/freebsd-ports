--- screen.c_orig	2008-12-21 22:41:24.000000000 +0800
+++ screen.c	2008-12-21 22:41:40.000000000 +0800
@@ -6,7 +6,8 @@
 /* update : 95/12/15                                     */
 /*-------------------------------------------------------*/
 
-#include <varargs.h>
+#include <stdarg.h>
+#include <stdlib.h>
 #include "bbs.h"
 
 extern char clearbuf[];
@@ -46,8 +47,6 @@
 {
   if (!dumb_term && !big_picture)
   {
-    extern char *calloc();
-
     scr_lns = t_lines;
     scr_cols = t_columns = ANSILINELEN;
     /* scr_cols = MIN(t_columns, ANSILINELEN); */
@@ -601,13 +600,12 @@
 
 
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
