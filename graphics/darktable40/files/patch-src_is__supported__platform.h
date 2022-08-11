--- src/is_supported_platform.h.orig	2021-11-14 08:33:27 UTC
+++ src/is_supported_platform.h
@@ -30,7 +30,7 @@
 #define DT_SUPPORTED_X86 0
 #endif
 
-#if defined(__aarch64__) && (defined(__ARM_64BIT_STATE) && defined(__ARM_ARCH) && defined(__ARM_ARCH_8A) || defined(__APPLE__))
+#if defined(__aarch64__) && (defined(__ARM_64BIT_STATE) && defined(__ARM_ARCH) && defined(__ARM_ARCH_8A) || defined(__APPLE__) || defined(__FreeBSD__))
 #define DT_SUPPORTED_ARMv8A 1
 #else
 #define DT_SUPPORTED_ARMv8A 0
