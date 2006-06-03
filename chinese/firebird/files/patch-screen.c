--- src/screen.c.orig	Sat Jan 15 09:45:29 2000
+++ src/screen.c	Sat Jun  3 17:58:30 2006
@@ -27,7 +27,7 @@
 #include "screen.h"
 #include "edit.h"
 #include <sys/param.h>
-#include <varargs.h>
+#include <stdarg.h>
 
 extern char clearbuf[];
 extern char cleolbuf[];
@@ -538,15 +538,12 @@
 int     dec[] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
 
 void
-prints(va_alist)
-va_dcl
+prints(char *fmt, ...)
 {
 	va_list ap;
-	register char *fmt;
 	char   *bp;
 	register int i, count, hd, indx;
-	va_start(ap);
-	fmt = va_arg(ap, char *);
+	va_start(ap, fmt);
 	while (*fmt != '\0') {
 		if (*fmt == '%') {
 			int     sgn = 1;
