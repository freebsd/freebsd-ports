--- libs/ardour/ardour/cycles.h.orig	2023-01-03 16:39:59 UTC
+++ libs/ardour/ardour/cycles.h
@@ -72,12 +72,22 @@ static inline cycles_t get_cycles (void)
 
 #elif defined(__powerpc64__)
 
+#ifdef __linux__
 #include <sys/platform/ppc.h>
 typedef uint64_t cycles_t;
 static inline cycles_t get_cycles(void)
 {
 	return __ppc_get_timebase();
 }
+#elif defined(__FreeBSD__)
+typedef uint64_t cycles_t;
+static inline cycles_t get_cycles(void)
+{
+	cycles_t tbr;
+	asm volatile("mfspr %0, 268" : "=r"(tbr));
+	return tbr;
+}
+#endif
 
 #elif defined(__powerpc__)
 
