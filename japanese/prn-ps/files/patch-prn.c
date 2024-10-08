--- prn.c.orig	1994-05-26 02:37:45 UTC
+++ prn.c
@@ -26,16 +26,24 @@ static char sccsid[] = "@(#)prn.c 2.3 (Y
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <fcntl.h>
 #include <time.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include "euc.h"
 
+#if !defined KCCPATH
 #define KCCPATH		"/usr/local/bin/kcc"
-#if defined (__bsdi__)
+#endif
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+#if defined (__bsdi__) || (defined(BSD) && (BSD >= 199103))
 #define LPRPATH		"/usr/bin/lpr"
 #else
 #define LPRPATH		"/usr/ucb/lpr"
@@ -48,8 +56,12 @@ static char sccsid[] = "@(#)prn.c 2.3 (Y
 
 #else
 
+#if !defined CMTPATH
 #define CMTPATH		"/usr/local/bin/cmt"
+#endif
+#if !defined PSPATH
 #define PSPATH		"/usr/local/bin/psconv"
+#endif
 
 #endif
 
@@ -96,7 +108,7 @@ static char *rangestr = NULL;
 static char *filename;		/* name of the file being processed */
 static char *modtime;		/* the last modification time */
 
-static void error();
+static void error(char *, ...);
 static char *basename();
 static bool formatopt();
 static bool rangeopt();
@@ -498,16 +510,15 @@ int main(c, v)
 	error(format, arg1, arg2, ...)
 	    char *format;
  ---------------------------------------------------------------------*/
-#include <varargs.h>
+#include <stdarg.h>
 
-static void error(va_alist)
-    va_dcl
+static void error(char *a, ...)
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
