--- lib/CL/pocl_threads.c.orig	2025-10-08 11:14:14 UTC
+++ lib/CL/pocl_threads.c
@@ -64,18 +64,26 @@ int
 }
 
 int
-pocl_set_thread_stack_size (size_t ThreadStackSize)
+pocl_create_thread_with_stack_size (pthread_t *thread,
+                                    void *(*func) (void *),
+                                    void *arg,
+                                    size_t min_stack_size)
 {
-  pthread_attr_t PTAttr;
-#ifdef __linux__
-  if (pthread_getattr_np (pthread_self (), &PTAttr))
-    return -1;
-  int err = pthread_attr_setstacksize (&PTAttr, ThreadStackSize);
-  pthread_attr_destroy (&PTAttr);
+  pthread_attr_t attr;
+  int err = pthread_attr_init (&attr);
+  if (err)
+    return err;
+  /* Only ever grow the stack: the default can be larger than requested, e.g.
+     with a raised RLIMIT_STACK on Linux. If the size is rejected, fall back to
+     the default stack rather than failing; the thread can query what it got.
+   */
+  size_t default_size = 0;
+  if (pthread_attr_getstacksize (&attr, &default_size) == 0
+      && default_size < min_stack_size)
+    pthread_attr_setstacksize (&attr, min_stack_size);
+  err = pthread_create (thread, &attr, func, arg);
+  pthread_attr_destroy (&attr);
   return err;
-#else
-  return -1;
-#endif
 }
 
 size_t
