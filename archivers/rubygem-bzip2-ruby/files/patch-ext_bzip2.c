--- ext/bzip2.c.orig	2024-09-07 15:54:07 UTC
+++ ext/bzip2.c
@@ -247,9 +247,6 @@ static VALUE bz_writer_close(VALUE obj) {
 
     Get_BZ2(obj, bzf);
     res = bz_writer_internal_close(bzf);
-    if (!NIL_P(res) && (bzf->flags & BZ2_RB_INTERNAL)) {
-        RBASIC(res)->klass = rb_cString;
-    }
     return res;
 }
 
@@ -495,7 +492,7 @@ static VALUE bz_writer_init(int argc, VALUE *argv, VAL
             }
             bziv->bz2 = obj;
         } else {
-            iv = Data_Make_Struct(rb_cData, struct bz_iv, 0, free, bziv);
+            iv = Data_Make_Struct(rb_cObject, struct bz_iv, 0, free, bziv);
             bziv->io = a;
             bziv->bz2 = obj;
             rb_ary_push(bz_internal_ary, iv);
@@ -1733,7 +1730,7 @@ void Init_bzip2_ext() {
     /*
       Writer
     */
-    bz_cWriter = rb_define_class_under(bz_mBzip2, "Writer", rb_cData);
+    bz_cWriter = rb_define_class_under(bz_mBzip2, "Writer", rb_cObject);
 #if HAVE_RB_DEFINE_ALLOC_FUNC
     rb_define_alloc_func(bz_cWriter, bz_writer_s_alloc);
 #else
@@ -1757,7 +1754,7 @@ void Init_bzip2_ext() {
     /*
       Reader
     */
-    bz_cReader = rb_define_class_under(bz_mBzip2, "Reader", rb_cData);
+    bz_cReader = rb_define_class_under(bz_mBzip2, "Reader", rb_cObject);
     rb_include_module(bz_cReader, rb_mEnumerable);
 #if HAVE_RB_DEFINE_ALLOC_FUNC
     rb_define_alloc_func(bz_cReader, bz_reader_s_alloc);
@@ -1798,7 +1795,7 @@ void Init_bzip2_ext() {
     /*
       Internal
     */
-    bz_cInternal = rb_define_class_under(bz_mBzip2, "InternalStr", rb_cData);
+    bz_cInternal = rb_define_class_under(bz_mBzip2, "InternalStr", rb_cObject);
 #if HAVE_RB_DEFINE_ALLOC_FUNC
     rb_undef_alloc_func(bz_cInternal);
 #else
