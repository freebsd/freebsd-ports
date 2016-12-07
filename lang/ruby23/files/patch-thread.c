--- thread.c.orig	2015-12-09 01:38:32.000000000 +0100
+++ thread.c	2016-01-10 19:24:26.106834000 +0100
@@ -466,8 +466,8 @@ rb_threadptr_unlock_all_locking_mutexes(
 void
 rb_thread_terminate_all(void)
 {
-    rb_thread_t *th = GET_THREAD(); /* main thread */
-    rb_vm_t *vm = th->vm;
+    rb_thread_t *volatile th = GET_THREAD(); /* main thread */
+    rb_vm_t *volatile vm = th->vm;
     volatile int sleeping = 0;
 
     if (vm->main_thread != th) {
