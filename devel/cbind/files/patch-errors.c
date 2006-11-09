--- errors.c.orig	Fri Oct 28 19:44:44 1994
+++ errors.c	Sat Nov  4 22:03:45 2006
@@ -1,5 +1,5 @@
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <errno.h>
 
 int Num_Errors;
@@ -33,75 +33,63 @@
 }
 
 void
-fatal(f, l, fmt, va_alist)
-	char *f, *fmt;
-	int l;
-	va_dcl
+fatal(char *f, int l, char *fmt, ...)
 {
-	va_list args;
+	va_list ap;
 
-	va_start(args);
+	va_start(ap, fmt);
 
 	prefix(f,l,"Internal error");
-	vfprintf(stderr, fmt, args);
+	vfprintf(stderr, fmt, ap);
 	endmsg();
 
-	va_end(args);
+	va_end(ap);
 
 	exit(1);
 }
 
 void
-error(f, l, fmt, va_alist)
-	char *f, *fmt;
-	int l;
-	va_dcl
+error(char *f, int l, char *fmt, ...)
 {
-	va_list args;
+	va_list ap;
 
-	va_start(args);
+	va_start(ap, fmt);
 
 	Num_Errors++;
 	prefix(f,l,"Error");
-	vfprintf(stderr, fmt, args);
+	vfprintf(stderr, fmt, ap);
 	endmsg();
 
-	va_end(args);
+	va_end(ap);
 }
 
 void
-warning(f, l, fmt, va_alist)
-	char *f, *fmt;
-	int l;
-	va_dcl
+warning(char *f, int l, char *fmt, ...)
 {
-	va_list args;
+	va_list ap;
 
-	va_start(args);
+	va_start(ap, fmt);
 
 	Num_Warnings++;
 	prefix(f,l,"Warning");
-	vfprintf(stderr, fmt, args);
+	vfprintf(stderr, fmt, ap);
 	endmsg();
 
-	va_end(args);
+	va_end(ap);
 }
 
 void
-inform(f, l, fmt, va_alist)
-	char *f, *fmt;
-	int l;
-	va_dcl
+inform(char *f, int l, char *fmt, ...)
 {
-	va_list args;
+	va_list ap;
 
-	va_start(args);
+	va_start(ap, fmt);
 
 	prefix(f,l,"Info");
-	vfprintf(stderr, fmt, args);
+	vfprintf(stderr, fmt, ap);
 	endmsg();
 
-	va_end(args);
+	va_end(ap);
 }
 
 void
@@ -118,9 +106,6 @@
 static void
 unix_error()
 {
-	extern char *sys_errlist[];
-	extern int sys_nerr;
-
 	if (errno != 0) {
 		if (errno > 0 && errno < sys_nerr) {
 			fputs(sys_errlist[errno], stderr);
