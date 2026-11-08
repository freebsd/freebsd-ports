--- contrib/rocksdb/utilities/transactions/lock/range/range_tree/lib/portability/toku_time.h.orig	2026-10-14 00:00:00 UTC
+++ contrib/rocksdb/utilities/transactions/lock/range/range_tree/lib/portability/toku_time.h
@@ -58,7 +58,7 @@
 #include <stdint.h>
 #include <sys/time.h>
 #include <time.h>
-#if defined(__powerpc__)
+#if defined(__powerpc__) && defined(__linux__)
 #include <sys/platform/ppc.h>
 #endif
 
@@ -132,7 +132,13 @@
   __asm __volatile__("mrs %[rt], cntvct_el0" : [rt] "=r"(result));
   return result;
 #elif defined(__powerpc__)
+#ifdef __linux__
   return __ppc_get_timebase();
+#elif defined(__FreeBSD__)
+  int64_t tbr;
+  asm volatile("mfspr %0, 268" : "=r"(tbr));
+  return tbr;
+#endif
 #elif defined(__s390x__)
   uint64_t result;
   asm volatile("stckf %0" : "=Q"(result) : : "cc");
