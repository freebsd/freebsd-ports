--- utilities/transactions/lock/range/range_tree/lib/portability/toku_time.h.orig	2021-10-17 17:02:20 UTC
+++ utilities/transactions/lock/range/range_tree/lib/portability/toku_time.h
@@ -58,7 +58,7 @@ Copyright (c) 2006, 2015, Percona and/or its affiliate
 #include <stdint.h>
 #include <sys/time.h>
 #include <time.h>
-#if defined(__powerpc__)
+#if defined(__powerpc__) && defined(__linux__)
 #include <sys/platform/ppc.h>
 #endif
 
@@ -132,7 +132,13 @@ static inline tokutime_t toku_time_now(void) {
   __asm __volatile__("mrs %[rt], cntvct_el0" : [ rt ] "=r"(result));
   return result;
 #elif defined(__powerpc__)
+#ifdef __linux__
   return __ppc_get_timebase();
+#elif defined(__FreeBSD__)
+  int64_t tbr;
+  asm volatile("mfspr %0, 268" : "=r"(tbr));
+  return tbr;
+#endif
 #else
 #error No timer implementation for this platform
 #endif
