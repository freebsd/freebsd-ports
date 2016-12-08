--- eval.c.orig	2015-01-21 17:09:59.000000000 +0100
+++ eval.c	2016-01-09 22:22:34.009232000 +0100
@@ -743,7 +743,7 @@ rb_rescue2(VALUE (* b_proc) (ANYARGS), V
 {
     int state;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t *volatile cfp = th->cfp;
     volatile VALUE result = Qfalse;
     volatile VALUE e_info = th->errinfo;
     va_list args;
@@ -809,7 +809,7 @@ rb_protect(VALUE (* proc) (VALUE), VALUE
     volatile VALUE result = Qnil;
     volatile int status;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t *volatile cfp = th->cfp;
     struct rb_vm_protect_tag protect_tag;
     rb_jmpbuf_t org_jmpbuf;
 
