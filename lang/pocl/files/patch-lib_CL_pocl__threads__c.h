--- lib/CL/pocl_threads_c.h.orig	2025-10-08 11:14:14 UTC
+++ lib/CL/pocl_threads_c.h
@@ -120,12 +120,17 @@ extern "C"
     }                                                                         \
   while (0)
 
+/* Create a thread with a stack of at least min_stack_size bytes, or the
+   default stack if the platform rejects that size. A running thread's stack
+   can't be resized, so this has to happen at creation. */
 POCL_EXPORT
-int pocl_set_thread_stack_size (size_t ThreadStackSize);
+int pocl_create_thread_with_stack_size (pthread_t *thread,
+                                        void *(*func) (void *),
+                                        void *arg,
+                                        size_t min_stack_size);
 POCL_EXPORT
 size_t pocl_get_thread_stack_size ();
 
-#define POCL_SET_THREAD_STACK_SIZE(N) pocl_set_thread_stack_size (N)
 #define POCL_GET_THREAD_STACK_SIZE() pocl_get_thread_stack_size ()
 
 /* Generic functionality for handling different types of
@@ -168,6 +173,8 @@ size_t pocl_get_thread_stack_size ();
 
 #define POCL_CREATE_THREAD(thr, func, arg)                                    \
   PTHREAD_CHECK (pthread_create (&thr, NULL, func, arg))
+#define POCL_CREATE_THREAD_WITH_STACK_SIZE(thr, func, arg, size)              \
+  PTHREAD_CHECK (pocl_create_thread_with_stack_size (&thr, func, arg, size))
 #define POCL_JOIN_THREAD(thr) PTHREAD_CHECK (pthread_join (thr, NULL))
 #define POCL_THREAD_SELF() pthread_self ()
 
