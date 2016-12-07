--- eval.c.orig	2015-11-20 01:17:25.000000000 +0100
+++ eval.c	2016-01-10 19:24:26.101707000 +0100
@@ -788,7 +788,7 @@ rb_rescue2(VALUE (* b_proc) (ANYARGS), V
 {
     int state;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t *volatile cfp = th->cfp;
     volatile VALUE result = Qfalse;
     volatile VALUE e_info = th->errinfo;
     va_list args;
@@ -854,7 +854,7 @@ rb_protect(VALUE (* proc) (VALUE), VALUE
     volatile VALUE result = Qnil;
     volatile int status;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t *volatile cfp = th->cfp;
     struct rb_vm_protect_tag protect_tag;
     rb_jmpbuf_t org_jmpbuf;
 
