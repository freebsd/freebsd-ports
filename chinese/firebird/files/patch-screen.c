--- src/screen.c.orig	Sat Jan 15 09:45:29 2000
+++ src/screen.c	Tue Mar  8 03:06:59 2005
@@ -27,7 +27,7 @@
 #include "screen.h"
 #include "edit.h"
 #include <sys/param.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 extern char clearbuf[];
 extern char cleolbuf[];
@@ -538,14 +538,13 @@
 int     dec[] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
 
 void
-prints(va_alist)
-va_dcl
+prints(char *fmt, ...)
 {
 	va_list ap;
-	register char *fmt;
+	register char;
 	char   *bp;
 	register int i, count, hd, indx;
-	va_start(ap);
+	va_start(ap, fmt);
 	fmt = va_arg(ap, char *);
 	while (*fmt != '\0') {
 		if (*fmt == '%') {
