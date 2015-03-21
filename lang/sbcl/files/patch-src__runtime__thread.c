--- src/runtime/thread.c.orig	2015-02-27 19:49:49.000000000 +0900
+++ src/runtime/thread.c	2015-03-07 18:27:45.000000000 +0900
@@ -520,10 +520,13 @@
     stack_addr = pthread_get_stackaddr_np(os);
     stack_size = pthread_get_stacksize_np(os);
 #else
-    pthread_attr_t attr;
+/*  pthread_attr_t attr;
     int pthread_getattr_np(pthread_t, pthread_attr_t *);
     pthread_getattr_np(os, &attr);
     pthread_attr_getstack(&attr, &stack_addr, &stack_size);
+*/
+    pthread_attr_getstackaddr(th->os_attr, &stack_addr);
+    pthread_attr_getstacksize(th->os_attr, &stack_size);
 #endif
 
     th->control_stack_start = stack_addr;
