--- code/client/cl_curl.h.orig	2011-11-03 10:16:32.000000000 +0100
+++ code/client/cl_curl.h	2011-11-03 10:16:56.000000000 +0100
@@ -34,8 +34,7 @@
 #elif defined(MACOS_X)
 #define DEFAULT_CURL_LIB "libcurl.dylib"
 #else
-#define DEFAULT_CURL_LIB "libcurl.so.4"
-#define ALTERNATE_CURL_LIB "libcurl.so.3"
+#define DEFAULT_CURL_LIB "libcurl.so"
 #endif
 
 #ifdef USE_LOCAL_HEADERS
