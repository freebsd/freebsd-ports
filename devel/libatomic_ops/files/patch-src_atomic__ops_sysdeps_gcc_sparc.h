--- src/atomic_ops/sysdeps/gcc/sparc.h.orig	2016-07-26 00:27:50 UTC
+++ src/atomic_ops/sysdeps/gcc/sparc.h
@@ -37,7 +37,7 @@ AO_test_and_set_full(volatile AO_TS_t *a
 }
 #define AO_HAVE_test_and_set_full
 
-#ifndef AO_NO_SPARC_V9
+#ifdef __sparc64__
 /* Returns nonzero if the comparison succeeded. */
 AO_INLINE int
 AO_compare_and_swap_full(volatile AO_t *addr, AO_t old, AO_t new_val) {
@@ -62,7 +62,7 @@ AO_compare_and_swap_full(volatile AO_t *
 #define AO_HAVE_compare_and_swap_full
 
 /* TODO: implement AO_fetch_compare_and_swap.   */
-#endif /* !AO_NO_SPARC_V9 */
+#endif /* __sparc64__ */
 
 /* TODO: Extend this for SPARC v8 and v9 (V8 also has swap, V9 has CAS, */
 /* there are barriers like membar #LoadStore, CASA (32-bit) and         */
