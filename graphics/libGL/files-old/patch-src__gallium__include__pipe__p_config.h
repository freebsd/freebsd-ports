--- ./src/gallium/include/pipe/p_config.h.orig	2014-02-03 18:42:39.000000000 +0100
+++ ./src/gallium/include/pipe/p_config.h	2014-02-15 21:11:34.000000000 +0100
@@ -81,6 +81,13 @@
 #define PIPE_CC_SUNPRO
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
