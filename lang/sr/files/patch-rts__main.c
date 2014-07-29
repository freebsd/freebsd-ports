--- rts/main.c.orig	Sat Dec 13 19:38:54 2003
+++ rts/main.c	Sat Dec 13 19:42:06 2003
@@ -16,7 +16,7 @@
 #endif
 
 
-#include <varargs.h>
+#include <stdarg.h>
 
 #define RUNERR(s,n,m) {n, m},
 static struct err {
@@ -311,20 +311,17 @@
  */
 /*VARARGS*/
 int
-sr_runerr (va_alist)
-va_dcl
+sr_runerr (char *locn, ...)
 {
     va_list ap;
     char c, *f, *o;
-    char *locn;
     int errnum;
     struct err *ep;
     char buf[200];
     Dim *d;
     String *s;
 
-    va_start (ap);
-    locn = va_arg (ap, char *);
+    va_start (ap, locn);
     errnum = va_arg (ap, int);
 
 
