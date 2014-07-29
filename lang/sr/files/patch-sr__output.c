--- sr/output.c.orig	Sat Dec 13 19:34:04 2003
+++ sr/output.c	Sat Dec 13 19:34:47 2003
@@ -8,7 +8,7 @@
 #include "compiler.h"
 #include <ctype.h>
 #include <errno.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 #define NSTREAMS 10		/* number of output streams */
 #define DEFSTREAM 9		/* default stream number */
@@ -231,11 +231,9 @@
 
 /* VARARGS */
 void
-cprintf (va_alist)
-va_dcl
+cprintf (char *fmt, ...)
 {
     va_list ap;
-    char *fmt;
     char *s;
     char c;
     int n, oldstream;
@@ -244,8 +242,7 @@
 
     oldstream = outstream;		/* save stream number in case changed */
 
-    va_start (ap);
-    fmt = va_arg (ap, char *);
+    va_start (ap, fmt);
 
     if (*fmt == ',' && LASTPUT () == '(')
 	fmt++;				/* skip initial comma inside parens */
