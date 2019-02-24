--- flow/Platform.h.orig	2019-01-09 22:28:32 UTC
+++ flow/Platform.h
@@ -22,7 +22,7 @@
 #define FLOW_PLATFORM_H
 #pragma once
 
-#if (defined(__linux__) || defined(__APPLE__))
+#if (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 #define __unixish__ 1
 #endif
 
@@ -182,6 +182,8 @@ THREAD_HANDLE startThread(void *(func) (void *), void 
 #if defined(_WIN32)
 #define DYNAMIC_LIB_EXT ".dll"
 #elif defined(__linux)
+#define DYNAMIC_LIB_EXT ".so"
+#elif defined(__FreeBSD__)
 #define DYNAMIC_LIB_EXT ".so"
 #elif defined(__APPLE__)
 #define DYNAMIC_LIB_EXT ".dylib"
