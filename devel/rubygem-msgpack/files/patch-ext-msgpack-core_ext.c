--- ext/msgpack/core_ext.c.orig	2018-01-03 15:29:36 UTC
+++ ext/msgpack/core_ext.c
@@ -118,8 +118,8 @@ void MessagePack_core_ext_module_init()
     rb_define_method(rb_cNilClass,   "to_msgpack", NilClass_to_msgpack, -1);
     rb_define_method(rb_cTrueClass,  "to_msgpack", TrueClass_to_msgpack, -1);
     rb_define_method(rb_cFalseClass, "to_msgpack", FalseClass_to_msgpack, -1);
-    rb_define_method(rb_cFixnum, "to_msgpack", Fixnum_to_msgpack, -1);
-    rb_define_method(rb_cBignum, "to_msgpack", Bignum_to_msgpack, -1);
+    rb_define_method(rb_cInteger, "to_msgpack", Fixnum_to_msgpack, -1);
+    rb_define_method(rb_cInteger, "to_msgpack", Bignum_to_msgpack, -1);
     rb_define_method(rb_cFloat,  "to_msgpack", Float_to_msgpack, -1);
     rb_define_method(rb_cString, "to_msgpack", String_to_msgpack, -1);
     rb_define_method(rb_cArray,  "to_msgpack", Array_to_msgpack, -1);
