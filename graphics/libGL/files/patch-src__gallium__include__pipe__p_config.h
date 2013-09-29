--- src/gallium/include/pipe/p_config.h.orig	2011-10-15 02:43:58.000000000 +0200
+++ src/gallium/include/pipe/p_config.h	2012-06-28 21:27:06.000000000 +0200
@@ -106,6 +106,13 @@
 #endif
 #endif
 
+#if defined(__sparc__) || defined(__sparc64__)
+#define PIPE_ARCH_SPARC
+#if defined(__sparc64__)
+#define PIPE_ARCH_SPARC_64
+#endif
+#endif
+
 
 /*
  * Endian detection.
@@ -133,7 +140,7 @@
 
 #if defined(PIPE_ARCH_X86) || defined(PIPE_ARCH_X86_64)
 #define PIPE_ARCH_LITTLE_ENDIAN
-#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64)
+#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64) || defined(PIPE_ARCH_SPARC) || defined(PIPE_ARCH_SPARC_64)
 #define PIPE_ARCH_BIG_ENDIAN
 #endif
 
