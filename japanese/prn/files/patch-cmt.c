--- cmt.c.orig	Mon Apr 25 16:26:57 1994
+++ cmt.c	Fri Feb  6 00:18:46 2004
@@ -352,16 +352,15 @@
 	error(format, arg1, arg2, ...)
 	    char *format;
  ---------------------------------------------------------------------*/
-#include <varargs.h>
+#include <stdarg.h>
 
-void error(va_alist)
-    va_dcl
+void error(char *a, ...)
 {
     va_list args;
 
-    va_start(args);
+    va_start(args, a);
     fprintf(stderr, "%s: ", progname);
-    vfprintf(stderr, va_arg(args, char *), args);
+    vfprintf(stderr, a, args);
     putc('\n', stderr);
     va_end(args);
     exit(1);
