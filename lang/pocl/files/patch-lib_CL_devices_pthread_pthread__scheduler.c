--- lib/CL/devices/pthread/pthread_scheduler.c.orig	2025-10-08 11:14:14 UTC
+++ lib/CL/devices/pthread/pthread_scheduler.c
@@ -48,6 +48,12 @@
 // of the commands in the work queue.
 //#define CPU_RANDOMIZE_QUEUE
 
+/* Kernels keep each work-item's private data that outlives a parallel region
+   on the worker's stack, replicated over the work-group, so large work-groups
+   need far more stack than the platform's default for secondary threads
+   (512 KiB on macOS). */
+#define WORKER_STACK_SIZE (8 * 1024 * 1024)
+
 static void* pocl_pthread_driver_thread (void *p);
 
 struct pool_thread_data
@@ -133,9 +139,9 @@ pthread_scheduler_init (cl_device_id device)
   for (i = 0; i < num_worker_threads; ++i)
     {
       scheduler.thread_pool[i].index = i;
-      POCL_CREATE_THREAD (scheduler.thread_pool[i].thread,
-                          pocl_pthread_driver_thread,
-                          (void *)&scheduler.thread_pool[i]);
+      POCL_CREATE_THREAD_WITH_STACK_SIZE (
+        scheduler.thread_pool[i].thread, pocl_pthread_driver_thread,
+        (void *)&scheduler.thread_pool[i], WORKER_STACK_SIZE);
 #ifdef ENABLE_SIGFPE_HANDLER
       pocl_ignore_sigfpe_for_thread (scheduler.thread_pool[i].thread);
 #endif
@@ -702,8 +708,6 @@ pocl_pthread_driver_thread (void *p)
                                            scheduler.printf_buf_size);
 
 #ifdef HOST_CPU_ENABLE_STACK_SIZE_CHECK
-  /* Try to set the stack size to 8MB */
-  POCL_SET_THREAD_STACK_SIZE (8 * 1024 * 1024);
   size_t stack_size = POCL_GET_THREAD_STACK_SIZE ();
   /* if the call fails, set a safe minimum */
   if (stack_size == 0)
