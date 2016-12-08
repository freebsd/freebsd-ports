--- vm_eval.c.orig	2015-07-03 10:55:40.000000000 +0200
+++ vm_eval.c	2016-01-10 18:53:23.030473000 +0100
@@ -1062,7 +1062,7 @@ rb_iterate(VALUE (* it_proc) (VALUE), VA
     int state;
     volatile VALUE retval = Qnil;
     NODE *node = NEW_IFUNC(bl_proc, data2);
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t *volatile th = GET_THREAD();
     rb_control_frame_t *volatile cfp = th->cfp;
 
     node->nd_aid = rb_frame_this_func();
@@ -1190,7 +1190,7 @@ eval_string_with_cref(VALUE self, VALUE 
     int state;
     VALUE result = Qundef;
     VALUE envval;
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t *volatile th = GET_THREAD();
     rb_env_t *env = NULL;
     rb_block_t block, *base_block;
     volatile int parse_in_eval;
@@ -1843,8 +1843,8 @@ rb_catch_protect(VALUE t, rb_block_call_
 {
     int state;
     volatile VALUE val = Qnil;		/* OK */
-    rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *saved_cfp = th->cfp;
+    rb_thread_t *volatile th = GET_THREAD();
+    rb_control_frame_t *volatile saved_cfp = th->cfp;
     volatile VALUE tag = t;
 
     TH_PUSH_TAG(th);
