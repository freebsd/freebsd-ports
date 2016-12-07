--- vm_eval.c.orig	2015-12-12 10:51:30.000000000 +0100
+++ vm_eval.c	2016-01-10 19:24:26.109468000 +0100
@@ -1267,7 +1267,7 @@ eval_string_with_cref(VALUE self, VALUE 
     int state;
     VALUE result = Qundef;
     VALUE envval;
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t *volatile th = GET_THREAD();
     rb_env_t *env = NULL;
     rb_block_t block, *base_block;
     volatile int parse_in_eval;
@@ -2001,8 +2001,8 @@ rb_catch_protect(VALUE t, rb_block_call_
 {
     int state;
     volatile VALUE val = Qnil;		/* OK */
-    rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *saved_cfp = th->cfp;
+    rb_thread_t *volatile th = GET_THREAD();
+    rb_control_frame_t *volatile saved_cfp = th->cfp;
     volatile VALUE tag = t;
 
     TH_PUSH_TAG(th);
