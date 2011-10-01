--- src/macro.c.orig	Sat Oct 18 23:46:14 2003
+++ src/macro.c	Sat Oct 18 23:47:36 2003
@@ -8,7 +8,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include "plain2.h"
 #include "macro.h"
 
@@ -189,9 +189,7 @@
 		buf++;
 	}
 }
-putMacro(macroNum, va_alist)
-int	macroNum;
-va_dcl
+putMacro(int macroNum, char *fmt, ...)
 {
 	va_list	ap;
 	union	macroArg {
@@ -226,7 +224,7 @@
 		}
 		mip = mip->cmac_next;
 	}
-	va_start(ap);
+	va_start(ap, fmt);
 	for (i = 1; i <= maxarg; i++) {
 		switch(argtype[i]) {
 		    case ATYPE_VOID:
