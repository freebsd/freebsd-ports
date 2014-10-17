--- ./src/gallium/include/pipe/p_config.h.orig	2014-01-23 18:02:42.000000000 +0100
+++ ./src/gallium/include/pipe/p_config.h	2014-02-23 22:01:50.000000000 +0100
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
