--- eval.c.orig	2016-11-14 17:36:10 UTC
+++ eval.c
@@ -804,7 +804,7 @@ rb_rescue2(VALUE (* b_proc) (ANYARGS), V
 {
     int state;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t *volatile cfp = th->cfp;
     volatile VALUE result = Qfalse;
     volatile VALUE e_info = th->errinfo;
     va_list args;
@@ -870,7 +870,7 @@ rb_protect(VALUE (* proc) (VALUE), VALUE
     volatile VALUE result = Qnil;
     volatile int status;
     rb_thread_t *th = GET_THREAD();
-    rb_control_frame_t *cfp = th->cfp;
+    rb_control_frame_t *volatile cfp = th->cfp;
     struct rb_vm_protect_tag protect_tag;
     rb_jmpbuf_t org_jmpbuf;
 
