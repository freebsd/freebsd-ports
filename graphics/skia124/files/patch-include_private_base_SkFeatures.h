--- include/private/base/SkFeatures.h.orig	2026-10-11 14:39:49 UTC
+++ include/private/base/SkFeatures.h
@@ -65,6 +65,10 @@
   #define SK_CPU_X86 1
 #endif
 
+#if defined(__powerpc__) || defined (__powerpc64__)
+  #define SK_CPU_PPC 1
+#endif
+
 /**
  *  SK_CPU_SSE_LEVEL
  *
