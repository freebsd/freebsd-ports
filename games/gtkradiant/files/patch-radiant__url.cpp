--- ./radiant/url.cpp.orig	Fri Feb 10 19:01:20 2006
+++ ./radiant/url.cpp	Thu Mar 16 16:09:46 2006
@@ -33,7 +33,7 @@
 }
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <stdlib.h>
 bool open_url(const char* url)
 {
