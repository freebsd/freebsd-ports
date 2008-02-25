--- src/pulsecore/atomic.h.orig	2008-01-23 19:44:20.000000000 -0500
+++ src/pulsecore/atomic.h	2008-02-25 14:02:59.000000000 -0500
@@ -106,6 +106,76 @@ static inline int pa_atomic_ptr_cmpxchg(
     return __sync_bool_compare_and_swap(&a->value, (long) old_p, (long) new_p);
 }
 
+#elif defined(__FreeBSD__)
+
+#include <sys/cdefs.h>
+#include <sys/types.h>
+#include <machine/atomic.h>
+
+typedef struct pa_atomic {
+	volatile unsigned long value;
+} pa_atomic_t;
+
+#define PA_ATOMIC_INIT(v) { .value = (v) }
+
+static inline int pa_atomic_load(const pa_atomic_t *a) {
+	return (int) atomic_load_acq_int((unsigned int *) &a->value);
+}
+
+static inline void pa_atomic_store(pa_atomic_t *a, int i) {
+	atomic_store_rel_int((unsigned int *) &a->value, i);
+}
+
+static inline int pa_atomic_add(pa_atomic_t *a, int i) {
+	return atomic_fetchadd_int((unsigned int *) &a->value, i);
+}
+
+static inline int pa_atomic_sub(pa_atomic_t *a, int i) {
+	return atomic_fetchadd_int((unsigned int *) &a->value, -(i));
+}
+
+static inline int pa_atomic_inc(pa_atomic_t *a) {
+	return atomic_fetchadd_int((unsigned int *) &a->value, 1);
+}
+
+static inline int pa_atomic_dec(pa_atomic_t *a) {
+	return atomic_fetchadd_int((unsigned int *) &a->value, -1);
+}
+
+static inline int pa_atomic_cmpxchg(pa_atomic_t *a, int old_i, int new_i) {
+	return atomic_cmpset_int((unsigned int *) &a->value, old_i, new_i);
+}
+
+typedef struct pa_atomic_ptr {
+	volatile unsigned long value;
+} pa_atomic_ptr_t;
+
+#define PA_ATOMIC_PTR_INIT(v) { .value = (unsigned long) (v) }
+
+static inline void* pa_atomic_ptr_load(const pa_atomic_ptr_t *a) {
+#ifdef atomic_load_acq_64
+	return (void*) atomic_load_acq_ptr((unsigned long *) &a->value);
+#else
+	return (void*) atomic_load_acq_ptr((unsigned int *) &a->value);
+#endif
+}
+
+static inline void pa_atomic_ptr_store(pa_atomic_ptr_t *a, void *p) {
+#ifdef atomic_load_acq_64
+	atomic_store_rel_ptr(&a->value, (unsigned long) p);
+#else
+	atomic_store_rel_ptr((unsigned int *) &a->value, (unsigned int) p);
+#endif
+}
+
+static inline int pa_atomic_ptr_cmpxchg(pa_atomic_ptr_t *a, void *old_p, void* new_p) {
+#ifdef atomic_load_acq_64
+	return atomic_cmpset_ptr(&a->value, (unsigned long) old_p, (unsigned long) new_p);
+#else
+	return atomic_cmpset_ptr((unsigned int *) &a->value, (unsigned int) old_p, (unsigned int) new_p);
+#endif
+}
+
 #elif defined(__GNUC__) && (defined(__amd64__) || defined(__x86_64__))
 
 #error "The native atomic operations implementation for AMD64 has not been tested. libatomic_ops is known to not work properly on AMD64 and your gcc version is too old for the gcc-builtin atomic ops support. You have three options now: make the native atomic operations implementation for AMD64 work, fix libatomic_ops, or upgrade your GCC."
