--- thread.c.orig	2015-02-20 14:53:23.000000000 +0100
+++ thread.c	2016-01-10 19:11:32.423524000 +0100
@@ -462,8 +462,8 @@ rb_threadptr_unlock_all_locking_mutexes(
 void
 rb_thread_terminate_all(void)
 {
-    rb_thread_t *th = GET_THREAD(); /* main thread */
-    rb_vm_t *vm = th->vm;
+    rb_thread_t *volatile th = GET_THREAD(); /* main thread */
+    rb_vm_t *volatile vm = th->vm;
 
     if (vm->main_thread != th) {
 	rb_bug("rb_thread_terminate_all: called by child thread (%p, %p)",
