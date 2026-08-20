--- flow/Platform.h.orig	2025-01-15 16:19:53 UTC
+++ flow/Platform.h
@@ -461,18 +461,20 @@ inline static uint64_t timestampCounter() {
 
 #ifdef __FreeBSD__
 #if !(__has_builtin(__rdtsc))
+#if defined(__amd64__)
 inline static uint64_t __rdtsc() {
 	uint64_t lo, hi;
 	asm("rdtsc" : "=a"(lo), "=d"(hi));
 	return (lo | (hi << 32));
 }
-#endif
 #elif defined(__powerpc64__) || defined(__ppc64__)
 inline static uint64_t __rdtsc() {
 	uint64_t tb;
 	__asm__ volatile("mfspr %0, 268" : "=r"(tb));
 	return tb;
 }
+#endif
+#endif
 #endif
 
 #if defined(__linux__)
