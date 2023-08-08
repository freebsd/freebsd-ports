--- src/delegator.c.orig	2011-04-06 19:35:39 UTC
+++ src/delegator.c
@@ -32,7 +32,7 @@ bdb_deleg_missing(int argc, VALUE *argv, VALUE obj)
     Data_Get_Struct(obj, struct deleg_class, delegst);
     if (rb_block_given_p()) {
 #if HAVE_RB_BLOCK_CALL
-	res = rb_block_call(delegst->obj, id_send, argc, argv, rb_yield, 0);
+	res = rb_block_call(delegst->obj, id_send, argc, argv, (rb_block_call_func_t)rb_yield, 0);
 #else
 	VALUE tmp[3];
 
