--- src/runtime/thread.c.orig	2013-01-01 06:24:20.000000000 -0500
+++ src/runtime/thread.c	2013-01-01 06:47:25.000000000 -0500
@@ -516,12 +516,10 @@
 #ifndef LISP_FEATURE_WIN32
     /* On windows, arch_os_thread_init will take care of finding the
      * stack. */
-    pthread_attr_t attr;
-    int pthread_getattr_np(pthread_t, pthread_attr_t *);
-    pthread_getattr_np(os, &attr);
     void *stack_addr;
     size_t stack_size;
-    pthread_attr_getstack(&attr, &stack_addr, &stack_size);
+    pthread_attr_getstackaddr(th->os_attr, &stack_addr);
+    pthread_attr_getstacksize(th->os_attr, &stack_size);
     th->control_stack_start = stack_addr;
     th->control_stack_end = (void *) (((uintptr_t) stack_addr) + stack_size);
 #endif
