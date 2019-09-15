--- src/pulsecore/atomic.h.orig	2019-09-13 13:10:23 UTC
+++ src/pulsecore/atomic.h
@@ -117,7 +117,7 @@ static inline void* pa_atomic_ptr_load(c
 }
 
 static inline void pa_atomic_ptr_store(pa_atomic_ptr_t *a, void* p) {
-    __atomic_store_n(&a->value, p, __ATOMIC_SEQ_CST);
+    __atomic_store_n(&a->value, (uintptr_t)p, __ATOMIC_SEQ_CST);
 }
 
 #else
@@ -218,39 +218,6 @@ static inline bool pa_atomic_ptr_cmpxchg
 #include <sys/param.h>
 #include <machine/atomic.h>
 
-#if __FreeBSD_version < 600000
-#if defined(__i386__) || defined(__amd64__)
-#if defined(__amd64__)
-#define atomic_load_acq_64      atomic_load_acq_long
-#endif
-static inline u_int atomic_fetchadd_int(volatile u_int *p, u_int v) {
-    __asm __volatile(
-            "   " __XSTRING(MPLOCKED) "         "
-            "   xaddl   %0, %1 ;        "
-            "# atomic_fetchadd_int"
-            : "+r" (v),
-            "=m" (*p)
-            : "m" (*p));
-
-    return (v);
-}
-#elif defined(__sparc__) && defined(__arch64__)
-#define atomic_load_acq_64      atomic_load_acq_long
-#define atomic_fetchadd_int     atomic_add_int
-#elif defined(__ia64__)
-#define atomic_load_acq_64      atomic_load_acq_long
-static inline uint32_t
-atomic_fetchadd_int(volatile uint32_t *p, uint32_t v) {
-    uint32_t value;
-
-    do {
-        value = *p;
-    } while (!atomic_cmpset_32(p, value, value + v));
-    return (value);
-}
-#endif
-#endif
-
 typedef struct pa_atomic {
     volatile unsigned long value;
 } pa_atomic_t;
