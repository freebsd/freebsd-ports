--- include/verilatedos_c.h.orig	2025-11-02 16:12:46 UTC
+++ include/verilatedos_c.h
@@ -41,6 +41,11 @@
 #if defined(__APPLE__) && !defined(__arm64__) && !defined(__POWERPC__)
 # include <cpuid.h>  // For __cpuid_count()
 #endif
+
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
+
 // clang-format on
 
 namespace VlOs {
