--- include/qemu/atomic.h.orig	2016-06-02 18:20:47 UTC
+++ include/qemu/atomic.h
@@ -136,10 +136,12 @@
 /* Provide shorter names for GCC atomic builtins, return old value */
 #define atomic_fetch_inc(ptr)  __atomic_fetch_add(ptr, 1, __ATOMIC_SEQ_CST)
 #define atomic_fetch_dec(ptr)  __atomic_fetch_sub(ptr, 1, __ATOMIC_SEQ_CST)
+#ifndef __cplusplus
 #define atomic_fetch_add(ptr, n) __atomic_fetch_add(ptr, n, __ATOMIC_SEQ_CST)
 #define atomic_fetch_sub(ptr, n) __atomic_fetch_sub(ptr, n, __ATOMIC_SEQ_CST)
 #define atomic_fetch_and(ptr, n) __atomic_fetch_and(ptr, n, __ATOMIC_SEQ_CST)
 #define atomic_fetch_or(ptr, n)  __atomic_fetch_or(ptr, n, __ATOMIC_SEQ_CST)
+#endif
 
 /* And even shorter names that return void.  */
 #define atomic_inc(ptr)    ((void) __atomic_fetch_add(ptr, 1, __ATOMIC_SEQ_CST))
@@ -330,10 +332,12 @@
 /* Provide shorter names for GCC atomic builtins.  */
 #define atomic_fetch_inc(ptr)  __sync_fetch_and_add(ptr, 1)
 #define atomic_fetch_dec(ptr)  __sync_fetch_and_add(ptr, -1)
+#ifndef __cplusplus
 #define atomic_fetch_add       __sync_fetch_and_add
 #define atomic_fetch_sub       __sync_fetch_and_sub
 #define atomic_fetch_and       __sync_fetch_and_and
 #define atomic_fetch_or        __sync_fetch_and_or
+#endif
 #define atomic_cmpxchg         __sync_val_compare_and_swap
 
 /* And even shorter names that return void.  */
