--- ext/bdb1/delegate.c.orig	2023-07-08 13:26:04 UTC
+++ ext/bdb1/delegate.c
@@ -33,7 +33,7 @@ bdb1_deleg_missing(int argc, VALUE *argv, VALUE obj)
 
     Data_Get_Struct(obj, struct deleg_class, delegst);
     if (rb_block_given_p()) {
-	res = rb_block_call(delegst->obj, id_send, argc, argv, rb_yield, 0);
+	res = rb_block_call(delegst->obj, id_send, argc, argv, (rb_block_call_func_t)rb_yield, 0);
     }
     else {
 	res = rb_funcall2(delegst->obj, id_send, argc, argv);
