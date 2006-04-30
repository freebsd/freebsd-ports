--- fbm.h.orig	Sat Feb 25 15:15:18 2006
+++ fbm.h	Sat Feb 25 15:17:11 2006
@@ -113,7 +113,7 @@
 char *strcpy();
 char *strncpy();
 
-#ifndef _COMPAT_
+#ifdef _COMPAT_
 char *malloc();
 #endif
 
