
$FreeBSD$

--- debug.c.orig	Tue Jan 12 19:59:35 1993
+++ debug.c	Mon Aug 25 00:38:35 2003
@@ -20,6 +20,10 @@
 
 # include "debug.h"
 
+#include "app.h"
+
+extern AppData app_data;
+
 /* VARARGS */
 void
 debug_printf(va_alist)
@@ -33,7 +37,7 @@
 	/*
 	 * first arg is whether or not to print.
 	 */
-	if ((va_arg(args, int) == 0) || (debug == False))
+	if ((va_arg(args, int) == 0) || (app_data.debug == False))
 		return;
 
 	fmt = va_arg(args, char *);
