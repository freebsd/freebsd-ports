--- rts/scan.c.orig	Sat Dec 13 19:38:54 2003
+++ rts/scan.c	Sat Dec 13 19:45:43 2003
@@ -1,7 +1,7 @@
 /*  scan.c -- scanf and sscanf  */
 
 #include <ctype.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include "rts.h"
 
 static int scanToken (), scanInteger (), scanReal (), scanPointer ();
@@ -58,11 +58,9 @@
  *  (or EOF).  The number of successful conversions is returned otherwise.
  */
 int
-sr_scanf (va_alist)
-va_dcl
+sr_scanf (char *locn, ...)
 {
     va_list ap;
-    char *locn;
     Array *a;
     String *sp, *sfmt, *sarg;
     Real *rp, real;
@@ -84,8 +82,7 @@
 
     sr_check_stk (CUR_STACK);
 
-    va_start (ap);
-    locn = va_arg (ap, char *);
+    va_start (ap, locn);
     fp = va_arg (ap, FILE *);
     sarg = va_arg (ap, String *);
     sfmt = va_arg (ap, String *);
