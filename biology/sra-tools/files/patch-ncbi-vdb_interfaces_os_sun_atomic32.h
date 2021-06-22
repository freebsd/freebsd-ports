--- ncbi-vdb/interfaces/os/sun/atomic32.h.orig	2021-03-15 18:16:43 UTC
+++ ncbi-vdb/interfaces/os/sun/atomic32.h
@@ -1,3 +1,66 @@
+#ifndef _h_atomic32_
+#define _h_atomic32_
+
+#include <sys/types.h>
+#include <machine/atomic.h>
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+/*
+ * /usr/src/sys/cddl/compat/opensolaris/sys/atomic.h
+ * BSD license
+ */
+
+#if defined(__i386__) || defined(__amd64__) || defined(__arm__)
+/* No spurious failures from fcmpset. */
+#define STRONG_FCMPSET
+#endif
+
+static inline uint32_t
+atomic_cas_32(volatile uint32_t *target, uint32_t cmp, uint32_t newval)
+{
+#ifdef STRONG_FCMPSET
+    (void) atomic_fcmpset_32(target, &cmp, newval);
+#else
+    uint32_t expected = cmp;
+
+    do {
+        if (atomic_fcmpset_32(target, &cmp, newval))
+            break;
+    } while (cmp == expected);
+#endif
+    return (cmp);
+}
+
+static inline void  atomic_inc_32(volatile uint32_t *target)
+{
+    atomic_add_32(target, 1);
+}
+
+static __inline uint32_t atomic_add_32_nv(volatile uint32_t *target, int32_t delta)
+{
+    return (atomic_fetchadd_32(target, delta) + delta);
+}
+
+static __inline uint32_t atomic_inc_32_nv(volatile uint32_t *target)
+{
+    return (atomic_add_32_nv(target, 1));
+}
+
+static __inline void
+atomic_dec_32(volatile uint32_t *target)
+{
+    atomic_subtract_32(target, 1);
+}
+    
+static __inline uint32_t
+atomic_dec_32_nv(volatile uint32_t *target)
+{
+    return (atomic_fetchadd_32(target, -1) - 1);
+}
+
 /*===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
@@ -23,15 +86,6 @@
 * ===========================================================================
 *
 */
-
-#ifndef _h_atomic32_
-#define _h_atomic32_
-
-#include <sys/atomic.h>
-
-#ifdef __cplusplus
-extern "C" {
-#endif
 
 #ifndef __inline__
 #define __inline__ inline
