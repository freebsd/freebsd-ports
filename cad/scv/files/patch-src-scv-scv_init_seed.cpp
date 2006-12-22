--- src/scv/scv_init_seed.cpp.orig	Thu Aug  7 08:37:32 2003
+++ src/scv/scv_init_seed.cpp	Sat Dec 16 11:43:50 2006
@@ -44,7 +44,7 @@
 
 #include <string.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <sys/time.h>
 #else 
 #include <time.h>
