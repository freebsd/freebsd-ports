--- vm_eval.c.orig	2015-11-29 10:01:12.000000000 +0100
+++ vm_eval.c	2016-01-10 19:11:40.066355000 +0100
@@ -1111,7 +1111,7 @@ rb_iterate(VALUE (* it_proc) (VALUE), VA
     int state;
     volatile VALUE retval = Qnil;
     NODE *node = NEW_IFUNC(bl_proc, data2);
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t *volatile th = GET_THREAD();
     rb_control_frame_t *volatile cfp = th->cfp;
 
     node->nd_aid = rb_frame_this_func();
@@ -1239,7 +1239,7 @@ eval_string_with_cref(VALUE self, VALUE 
     int state;
     VALUE result = Qundef;
     VALUE envval;
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t *volatile th = GET_THREAD();
     rb_env_t *env = NULL;
     rb_block_t block, *base_block;
     volatile int parse_in_eval;
@@ -1983,8 +1983,8 @@ rb_catch_protect(VALUE t, rb_block_call_
 {
     int state;
     volatile VALUE val = Qnil;		/* OK */
-    rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *saved_cfp = th->cfp;
+    rb_thread_t *volatile th = GET_THREAD();
+    rb_control_frame_t *volatile saved_cfp = th->cfp;
     volatile VALUE tag = t;
 
     TH_PUSH_TAG(th);
