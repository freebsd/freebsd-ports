--- include/qemu/atomic.h.orig	2017-04-20 14:57:00 UTC
+++ include/qemu/atomic.h
@@ -182,10 +182,12 @@
 /* Provide shorter names for GCC atomic builtins, return old value */
 #define atomic_fetch_inc(ptr)  __atomic_fetch_add(ptr, 1, __ATOMIC_SEQ_CST)
 #define atomic_fetch_dec(ptr)  __atomic_fetch_sub(ptr, 1, __ATOMIC_SEQ_CST)
+#ifndef __cplusplus
 #define atomic_fetch_add(ptr, n) __atomic_fetch_add(ptr, n, __ATOMIC_SEQ_CST)
 #define atomic_fetch_sub(ptr, n) __atomic_fetch_sub(ptr, n, __ATOMIC_SEQ_CST)
 #define atomic_fetch_and(ptr, n) __atomic_fetch_and(ptr, n, __ATOMIC_SEQ_CST)
 #define atomic_fetch_or(ptr, n)  __atomic_fetch_or(ptr, n, __ATOMIC_SEQ_CST)
+#endif
 #define atomic_fetch_xor(ptr, n) __atomic_fetch_xor(ptr, n, __ATOMIC_SEQ_CST)
 
 #define atomic_inc_fetch(ptr)    __atomic_add_fetch(ptr, 1, __ATOMIC_SEQ_CST)
@@ -199,10 +201,12 @@
 /* And even shorter names that return void.  */
 #define atomic_inc(ptr)    ((void) __atomic_fetch_add(ptr, 1, __ATOMIC_SEQ_CST))
 #define atomic_dec(ptr)    ((void) __atomic_fetch_sub(ptr, 1, __ATOMIC_SEQ_CST))
+#ifndef __cplusplus
 #define atomic_add(ptr, n) ((void) __atomic_fetch_add(ptr, n, __ATOMIC_SEQ_CST))
 #define atomic_sub(ptr, n) ((void) __atomic_fetch_sub(ptr, n, __ATOMIC_SEQ_CST))
 #define atomic_and(ptr, n) ((void) __atomic_fetch_and(ptr, n, __ATOMIC_SEQ_CST))
 #define atomic_or(ptr, n)  ((void) __atomic_fetch_or(ptr, n, __ATOMIC_SEQ_CST))
+#endif
 #define atomic_xor(ptr, n) ((void) __atomic_fetch_xor(ptr, n, __ATOMIC_SEQ_CST))
 
 #else /* __ATOMIC_RELAXED */
@@ -370,10 +374,12 @@
 
 #define atomic_inc_fetch(ptr)  __sync_add_and_fetch(ptr, 1)
 #define atomic_dec_fetch(ptr)  __sync_add_and_fetch(ptr, -1)
+#ifndef __cplusplus
 #define atomic_add_fetch(ptr, n) __sync_add_and_fetch(ptr, n)
 #define atomic_sub_fetch(ptr, n) __sync_sub_and_fetch(ptr, n)
 #define atomic_and_fetch(ptr, n) __sync_and_and_fetch(ptr, n)
 #define atomic_or_fetch(ptr, n) __sync_or_and_fetch(ptr, n)
+#endif
 #define atomic_xor_fetch(ptr, n) __sync_xor_and_fetch(ptr, n)
 
 #define atomic_cmpxchg(ptr, old, new) __sync_val_compare_and_swap(ptr, old, new)
@@ -382,10 +388,12 @@
 /* And even shorter names that return void.  */
 #define atomic_inc(ptr)        ((void) __sync_fetch_and_add(ptr, 1))
 #define atomic_dec(ptr)        ((void) __sync_fetch_and_add(ptr, -1))
+#ifndef __cplusplus
 #define atomic_add(ptr, n)     ((void) __sync_fetch_and_add(ptr, n))
 #define atomic_sub(ptr, n)     ((void) __sync_fetch_and_sub(ptr, n))
 #define atomic_and(ptr, n)     ((void) __sync_fetch_and_and(ptr, n))
 #define atomic_or(ptr, n)      ((void) __sync_fetch_and_or(ptr, n))
+#endif
 #define atomic_xor(ptr, n)     ((void) __sync_fetch_and_xor(ptr, n))
 
 #endif /* __ATOMIC_RELAXED */
