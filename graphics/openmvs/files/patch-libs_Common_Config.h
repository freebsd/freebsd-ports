--- libs/Common/Config.h.orig	2022-07-26 08:34:06 UTC
+++ libs/Common/Config.h
@@ -144,7 +144,9 @@
 #endif
 
 
-#if defined(__arm__) || defined (__arm64__) || defined(__aarch64__) || defined(_M_ARM) || defined(_M_ARMT)
+#if defined(__powerpc__)
+#define _PLATFFORM_PPC 1
+#elif defined(__arm__) || defined (__arm64__) || defined(__aarch64__) || defined(_M_ARM) || defined(_M_ARMT)
 #define _PLATFORM_ARM 1
 #else
 #define _PLATFORM_X86 1
