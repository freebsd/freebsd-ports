--- cmt.c.orig	1994-04-25 07:26:57 UTC
+++ cmt.c
@@ -27,7 +27,9 @@ static char *sccsid = "@(#)cmt.c 2.2 (Y.
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include "cmt.h"
@@ -352,16 +354,15 @@ static char_t *readkeyword(filename)
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
