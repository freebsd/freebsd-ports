--- rts/io.c.orig	Sat Dec 13 19:38:54 2003
+++ rts/io.c	Sat Dec 13 19:41:34 2003
@@ -7,7 +7,7 @@
  */
 
 #include <ctype.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include "rts.h"
 
 #define NOTHING			/* for use as null macro arg under ANSI C */
@@ -218,11 +218,9 @@
  */
 /*VARARGS*/
 int
-sr_read (va_alist)
-va_dcl
+sr_read (char *locn, ...)
 {
     va_list ap;
-    char *locn;
     File fp;
     char *argt;
     Array *a;
@@ -238,8 +236,7 @@
     double d;
 
     sr_check_stk (CUR_STACK);
-    va_start (ap);
-    locn = va_arg (ap, char *);
+    va_start (ap, locn);
 
     fp = va_arg (ap, File);
     BEGIN_IO (fp);
@@ -442,8 +439,7 @@
  */
 /*VARARGS*/
 void
-sr_printf (va_alist)
-va_dcl
+sr_printf (char *locn, ...)
 {
     va_list ap;
     File fp;
@@ -451,14 +447,12 @@
     double v;
     char xbuf[20], fbuf[512], dbuf[512], obuf[512];
     int n;
-    char *locn;
     String *str, *sp;
     int ssize;
     Array *arr;
 
     sr_check_stk (CUR_STACK);
-    va_start (ap);
-    locn = va_arg (ap, char *);
+    va_start (ap, locn);
     fp = va_arg (ap, File);
     sp = va_arg (ap, String *);
 
