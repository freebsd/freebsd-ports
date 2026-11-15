--- lib/CL/pocl_threads_cpp.hh.orig	2025-10-08 11:14:14 UTC
+++ lib/CL/pocl_threads_cpp.hh
@@ -56,7 +56,6 @@ typedef struct _pocl_thread_t *pocl_thread_t;
 #error Need atomic_inc() builtin for this compiler
 #endif
 
-#define POCL_SET_THREAD_STACK_SIZE(N) (void *)0
 #define POCL_GET_THREAD_STACK_SIZE() 0
 
 #ifdef __cplusplus
@@ -119,6 +118,9 @@ void pocl_barrier_destroy(pocl_barrier_t *B);
 #define POCL_TIMEDWAIT_COND(c, m, t) pocl_cond_timedwait(c, m, t)
 
 #define POCL_CREATE_THREAD(thr, func, arg) pocl_thread_create(&thr, func, arg)
+// std::thread can't set the stack size; threads get the platform default.
+#define POCL_CREATE_THREAD_WITH_STACK_SIZE(thr, func, arg, size)               \
+  pocl_thread_create(&thr, func, arg)
 #define POCL_JOIN_THREAD(thr) pocl_thread_join(thr)
 #define POCL_THREAD_SELF() pocl_thread_self()
 
