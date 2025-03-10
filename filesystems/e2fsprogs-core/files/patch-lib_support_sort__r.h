--- lib/support/sort_r.h.orig	2024-05-21 02:52:47 UTC
+++ lib/support/sort_r.h
@@ -238,10 +238,6 @@ static _SORT_R_INLINE void sort_r_simple(void *base, s
 
   #if defined _SORT_R_BSD
 
-    /* Ensure qsort_r is defined */
-    extern void qsort_r(void *base, size_t nel, size_t width, void *thunk,
-                        int (*compar)(void *_thunk,
-                                      const void *_a, const void *_b));
 
   #endif
 
