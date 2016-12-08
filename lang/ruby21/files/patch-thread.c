--- thread.c.orig	2015-03-09 18:40:36.000000000 +0100
+++ thread.c	2016-01-10 18:50:57.451040000 +0100
@@ -420,8 +420,8 @@ rb_threadptr_unlock_all_locking_mutexes(
 void
 rb_thread_terminate_all(void)
 {
-    rb_thread_t *th = GET_THREAD(); /* main thread */
-    rb_vm_t *vm = th->vm;
+    rb_thread_t *volatile th = GET_THREAD(); /* main thread */
+    rb_vm_t *volatile vm = th->vm;
 
     if (vm->main_thread != th) {
 	rb_bug("rb_thread_terminate_all: called by child thread (%p, %p)",
