--- thirdparty/cpuid/platform/src/platform/config.hpp.orig	2021-09-23 02:15:16 UTC
+++ thirdparty/cpuid/platform/src/platform/config.hpp
@@ -16,6 +16,8 @@
     #if defined(__ANDROID__)
         #define PLATFORM_ANDROID 1
     #endif
+#elif defined(__FreeBSD__)
+    #define PLATFORM_FREEBSD 1
 #elif defined(_WIN32)
     #define PLATFORM_WINDOWS 1
     #if defined(WINAPI_FAMILY)
