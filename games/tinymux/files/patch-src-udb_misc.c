--- udb_misc.c.orig	Tue Oct 28 01:01:25 2003
+++ udb_misc.c	Tue Oct 28 01:01:47 2003
@@ -40,9 +40,9 @@
  * VARARGS 
  */
 #ifdef STDC_HEADERS
-void logf(char *p,...)
+void Logf(char *p,...)
 #else
-void logf(va_alist)
+void Logf(va_alist)
 va_dcl
 
 #endif
