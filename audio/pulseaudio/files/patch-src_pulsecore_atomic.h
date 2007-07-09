--- src/pulsecore/atomic.h.orig	Sun May 27 16:38:18 2007
+++ src/pulsecore/atomic.h	Sun Jul  8 20:29:53 2007
@@ -24,7 +24,9 @@
   USA.
 ***/
 
-#include <atomic_ops.h>
+#include <sys/cdefs.h>
+#include <sys/types.h>
+#include <machine/atomic.h>
 
 /* atomic_ops guarantees us that sizeof(AO_t) == sizeof(void*).
  *
@@ -32,7 +34,7 @@
  * however very likely. */
 
 typedef struct pa_atomic_int {
-    volatile AO_t value;
+    volatile unsigned long value;
 } pa_atomic_int_t;
 
 #define PA_ATOMIC_INIT(v) { .value = (v) }
@@ -42,47 +44,64 @@ typedef struct pa_atomic_int {
  * suffixes to the function names */
 
 static inline int pa_atomic_load(const pa_atomic_int_t *a) {
-    return (int) AO_load_full((AO_t*) &a->value);
+    return (int) atomic_load_acq_int((unsigned int *) &a->value);
 }
 
 static inline void pa_atomic_store(pa_atomic_int_t *a, int i) {
-    AO_store_full(&a->value, (AO_t) i);
+    atomic_store_rel_int((unsigned int *) &a->value, i);
 }
 
 static inline int pa_atomic_add(pa_atomic_int_t *a, int i) {
-    return AO_fetch_and_add_full(&a->value, (AO_t) i);
+    atomic_add_int((unsigned int *) &a->value, i);
+    return (int) a->value;
 }
 
 static inline int pa_atomic_sub(pa_atomic_int_t *a, int i) {
-    return AO_fetch_and_add_full(&a->value, (AO_t) -i);
+    atomic_subtract_int((unsigned int *) &a->value, i);
+    return (int) a->value;
 }
 
 static inline int pa_atomic_inc(pa_atomic_int_t *a) {
-    return AO_fetch_and_add1_full(&a->value);
+    atomic_add_int((unsigned int *) &a->value, 1);
+    return (int) a->value;
 }
 
 static inline int pa_atomic_dec(pa_atomic_int_t *a) {
-    return AO_fetch_and_sub1_full(&a->value);
+    atomic_subtract_int((unsigned int *) &a->value, 1);
+    return (int) a->value;
 }
 
 static inline int pa_atomic_cmpxchg(pa_atomic_int_t *a, int old_i, int new_i) {
-    return AO_compare_and_swap_full(&a->value, old_i, new_i);
+    atomic_cmpset_int((unsigned int *) &a->value, old_i, new_i);
+    return (int) a->value;
 }
 
 typedef struct pa_atomic_ptr {
-    volatile AO_t value;
+    volatile unsigned long value;
 } pa_atomic_ptr_t;
 
 static inline void* pa_atomic_ptr_load(const pa_atomic_ptr_t *a) {
-    return (void*) AO_load_full((AO_t*) &a->value);
+#ifdef atomic_load_acq_long
+    return (void*) atomic_load_acq_ptr((unsigned long *) &a->value);
+#else
+    return (void*) atomic_load_acq_ptr((unsigned int *) &a->value);
+#endif
 }
 
 static inline void pa_atomic_ptr_store(pa_atomic_ptr_t *a, void *p) {
-    AO_store_full(&a->value, (AO_t) p);
+#ifdef atomic_load_acq_long
+    atomic_store_rel_ptr(&a->value, (unsigned long) p);
+#else
+    atomic_store_rel_ptr((unsigned int *) &a->value, (unsigned int) p);
+#endif
 }
 
 static inline int pa_atomic_ptr_cmpxchg(pa_atomic_ptr_t *a, void *old_p, void* new_p) {
-    return AO_compare_and_swap_full(&a->value, (AO_t) old_p, (AO_t) new_p);
+#ifdef atomic_load_acq_long
+    return atomic_cmpset_ptr(&a->value, (unsigned long) old_p, (unsigned long) new_p);
+#else
+    return atomic_cmpset_ptr((unsigned int *) &a->value, (unsigned int) old_p, (unsigned int) new_p);
+#endif
 }
 
 #endif
