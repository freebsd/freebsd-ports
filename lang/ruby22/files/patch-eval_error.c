--- eval_error.c.orig	2016-11-14 18:37:39 UTC
+++ eval_error.c
@@ -63,9 +63,9 @@ static void
 error_print(void)
 {
     volatile VALUE errat = Qundef;
-    rb_thread_t *th = GET_THREAD();
-    VALUE errinfo = th->errinfo;
-    int raised_flag = th->raised_flag;
+    rb_thread_t *volatile th = GET_THREAD();
+    volatile VALUE errinfo = th->errinfo;
+    volatile int raised_flag = th->raised_flag;
     volatile VALUE eclass = Qundef, e = Qundef;
     const char *volatile einfo;
     volatile long elen;
