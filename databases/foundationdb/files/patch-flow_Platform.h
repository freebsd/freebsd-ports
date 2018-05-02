--- flow/Platform.h.orig	2018-04-22 14:30:05 UTC
+++ flow/Platform.h
@@ -22,7 +22,7 @@
 #define FLOW_PLATFORM_H
 #pragma once
 
-#if (defined(__linux__) || defined(__APPLE__))
+#if (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 #define __unixish__ 1
 #endif
 
@@ -183,6 +183,8 @@ THREAD_HANDLE startThread(void *(func) (
 #define DYNAMIC_LIB_EXT ".dll"
 #elif defined(__linux)
 #define DYNAMIC_LIB_EXT ".so"
+#elif defined(__FreeBSD__)
+#define DYNAMIC_LIB_EXT ".so"
 #elif defined(__APPLE__)
 #define DYNAMIC_LIB_EXT ".dylib"
 #else
