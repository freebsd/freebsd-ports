--- src/gallium/include/pipe/p_config.h.orig	2016-11-10 22:05:17 UTC
+++ src/gallium/include/pipe/p_config.h
@@ -76,6 +76,13 @@
 #define PIPE_CC_ICL
 #endif
 
+#if defined(__sparc__) || defined(__sparc64__)
+#define PIPE_ARCH_SPARC
+#if defined(__sparc64__)
+#define PIPE_ARCH_SPARC_64
+#endif
+#endif
+
 
 /*
  * Processor architecture
@@ -130,7 +137,7 @@
 
 #if defined(PIPE_ARCH_X86) || defined(PIPE_ARCH_X86_64) || defined(PIPE_ARCH_ARM) || defined(PIPE_ARCH_AARCH64)
 #define PIPE_ARCH_LITTLE_ENDIAN
-#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64) || defined(PIPE_ARCH_S390)
+#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64) || defined(PIPE_ARCH_S390) || defined(PIPE_ARCH_SPARC) || defined(PIPE_ARCH_SPARC_64)
 #define PIPE_ARCH_BIG_ENDIAN
 #endif
 
@@ -159,6 +166,12 @@
 #define PIPE_OS_ANDROID
 #endif
 
+#if defined(__DragonFly__)
+#define PIPE_OS_DRAGONFLY
+#define PIPE_OS_BSD
+#define PIPE_OS_UNIX
+#endif
+
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #define PIPE_OS_FREEBSD
 #define PIPE_OS_BSD
