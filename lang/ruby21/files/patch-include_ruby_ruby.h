--- include/ruby/ruby.h.orig	2015-09-20 20:49:26 UTC
+++ include/ruby/ruby.h
@@ -228,7 +228,7 @@ typedef char ruby_check_sizeof_voidp[SIZ
 #define FIXNUM_MAX (LONG_MAX>>1)
 #define FIXNUM_MIN RSHIFT((long)LONG_MIN,1)
 
-#define INT2FIX(i) ((VALUE)(((SIGNED_VALUE)(i))<<1 | FIXNUM_FLAG))
+#define INT2FIX(i) (((VALUE)(i))<<1 | FIXNUM_FLAG)
 #define LONG2FIX(i) INT2FIX(i)
 #define rb_fix_new(v) INT2FIX(v)
 VALUE rb_int2inum(SIGNED_VALUE);
