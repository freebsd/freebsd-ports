--- include/cpu_features_macros.h.orig	2021-09-16 15:06:15 UTC
+++ include/cpu_features_macros.h
@@ -83,6 +83,10 @@
 #define CPU_FEATURES_OS_DARWIN
 #endif
 
+#if (defined(__freebsd__) || defined(__FreeBSD__))
+#define CPU_FEATURES_OS_FREEBSD
+#endif
+
 ////////////////////////////////////////////////////////////////////////////////
 // Compilers
 ////////////////////////////////////////////////////////////////////////////////
