--- vendor/naett/naett.c.orig	2023-09-08 19:55:43 UTC
+++ vendor/naett/naett.c
@@ -22,7 +22,7 @@
 #define __WINDOWS__ 1
 #endif
 
-#if __linux__ && !__ANDROID__
+#if __linux__ && !__ANDROID__ || __FreeBSD__
 #define __LINUX__ 1
 #include <curl/curl.h>
 #endif
@@ -782,7 +782,7 @@ void naettPlatformCloseResponse(InternalResponse* res)
 // Inlined naett_linux.c: //
 //#include "naett_internal.h"
 
-#if __linux__ && !__ANDROID__
+#if __linux__ && !__ANDROID__ || __FreeBSD__
 
 #include <curl/curl.h>
 #include <assert.h>
