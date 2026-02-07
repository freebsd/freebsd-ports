--- ext/native_server.c.orig	2015-05-27 17:48:45 UTC
+++ ext/native_server.c
@@ -153,11 +153,7 @@ static VALUE mc_initialize(VALUE self, V
   return self;
 }
 
-#if defined(RUBY_19) || defined(RUBY_20)
 #define RSTRING_SET_LEN(str, newlen) (rb_str_set_len(str, new_len))
-#else
-#define RSTRING_SET_LEN(str, newlen) (RSTRING(str)->len = new_len)
-#endif
 
 static VALUE escape_key(VALUE key, bool* escaped) {
   char*    str = RSTRING_PTR(key);
