--- lib/isc/rwlock.c.orig	2018-09-25 13:20:09 UTC
+++ lib/isc/rwlock.c
@@ -44,9 +44,11 @@
 #if defined(_MSC_VER)
 # include <intrin.h>
 # define isc_rwlock_pause() YieldProcessor()
-#elif defined(__x86_64__) || defined(__i386__)
+#elif defined(__x86_64__)
 # include <immintrin.h>
 # define isc_rwlock_pause() _mm_pause()
+#elif defined(__i386__)
+# define isc_rwlock_pause() asm("rep; nop")
 #elif defined(__ia64__)
 # define isc_rwlock_pause() __asm__ __volatile__ ("hint @pause")
 #elif defined(__arm__)
