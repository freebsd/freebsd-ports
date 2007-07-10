--- ext/dl/dl.c.orig	Tue Feb 13 02:01:19 2007
+++ ext/dl/dl.c	Mon Mar 19 10:43:56 2007
@@ -459,7 +459,7 @@
   VALUE val0;
 
   val0 = rb_check_array_type(v);
-  if(NIL_P(TYPE(val0))) {
+  if(NIL_P(val0)) {
     rb_raise(rb_eDLTypeError, "an array is expected.");
   }
   v = val0;
