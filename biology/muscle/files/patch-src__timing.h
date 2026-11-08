--- timing.h.orig	2026-08-29 19:42:39 UTC
+++ timing.h
@@ -17,14 +17,14 @@ __inline__ uint64_t GetClockTicks()
 	}
 
 #elif __GNUC__
+#include <time.h>
 
 typedef uint64_t TICKS;
 __inline__ uint64_t GetClockTicks()
 	{
-	uint32_t lo, hi;
-	/* We cannot use "=A", since this would use %rax on x86_64 */
-	__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
-	return (uint64_t)hi << 32 | lo;
+	struct timespec ts;
+	clock_gettime(CLOCK_MONOTONIC, &ts);
+	return (uint64_t)ts.tv_sec * 1000000000 + ts.tv_nsec;
 	}
 
 #else
