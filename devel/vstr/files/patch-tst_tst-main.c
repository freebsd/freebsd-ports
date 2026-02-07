--- tst/tst-main.c.orig	Fri Jul 30 09:15:06 2004
+++ tst/tst-main.c	Fri Jul 21 15:45:07 2006
@@ -133,7 +133,7 @@
     die();
 
 #ifndef USE_RESTRICTED_HEADERS
-  if (!setlocale(LC_ALL, "en_US"))
+  if (!setlocale(LC_ALL, "en_US.ISO8859-1"))
   {
     fprintf(stderr,
 " This library does things with the locale.\n"
