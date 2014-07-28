--- kcc.c.dist	Mon Mar 28 20:00:12 1994
+++ kcc.c	Wed Jan 21 06:01:11 2004
@@ -134,7 +134,7 @@
 extern unsigned short hiragana[];
 unsigned short *kanatbl = katakana;
 
-void error();
+void error(char* fmt, ...);
 
 /**********************************************************************
  *                                                                    *
@@ -364,18 +364,17 @@
     NAME
 	error - print formatted error message on stderr and die
  ---------------------------------------------------------------------*/
-#include <varargs.h>
+#include <stdarg.h>
 
-void error(va_alist)
-    va_dcl
+void error(char *fmt, ...)
 {
-    va_list args;
+    va_list ap;
 
-    va_start(args);
+    va_start(ap, fmt);
     fprintf(stderr, "%s: ", progname);
-    vfprintf(stderr, va_arg(args, char *), args);
+    vfprintf(stderr, fmt, ap);
     putc('\n', stderr);
-    va_end(args);
+    va_end(ap);
     exit(1);
 }
 
