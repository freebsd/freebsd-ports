
$FreeBSD$

--- debug.c.orig	Tue Jan 12 19:59:35 1993
+++ debug.c	Mon Aug 25 01:36:43 2003
@@ -15,28 +15,29 @@
 
 # include <X11/Intrinsic.h>
 
-# include <varargs.h>
+# include <stdarg.h>
 # include <stdio.h>
 
 # include "debug.h"
 
+#include "app.h"
+
+extern AppData app_data;
+
 /* VARARGS */
 void
-debug_printf(va_alist)
-	va_dcl
+debug_printf(int flag, char *fmt, ...)
 {
 	va_list		args;
-	char		*fmt;
 
-	va_start(args);
+	va_start(args, fmt);
 
 	/*
 	 * first arg is whether or not to print.
 	 */
-	if ((va_arg(args, int) == 0) || (debug == False))
+	if ((flag == 0) || (app_data.debug == False))
 		return;
 
-	fmt = va_arg(args, char *);
 	vfprintf(stdout, fmt, args);
 
 	fflush(stdout);
