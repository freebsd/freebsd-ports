--- trek/utility.c.orig	Sat Jul 26 00:02:02 2003
+++ trek/utility.c	Sat Jul 26 00:14:18 2003
@@ -43,7 +43,7 @@
 **  ASSORTED UTILITY ROUTINES
 */
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 /*
 **  BLOCK MOVE
@@ -143,14 +143,12 @@
 **  SYSTEM ERROR
 */
 
-syserr(fmt, va_alist)
-const char *fmt;
-va_dcl
+syserr(char *fmt,...)
 {
 	va_list		ap;
 	extern int	errno;
 
-	va_start(ap);
+	va_start(ap,fmt);
 	printf("\n\07TREK SYSERR: ");
 	vfprintf(stdout, fmt, ap);
 	printf("\n");
