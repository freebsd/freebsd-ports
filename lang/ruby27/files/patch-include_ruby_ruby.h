--- include/ruby/ruby.h.orig	2021-04-05 12:39:38 UTC
+++ include/ruby/ruby.h
@@ -1828,12 +1828,14 @@ VALUE rb_sym2str(VALUE);
 VALUE rb_to_symbol(VALUE name);
 VALUE rb_check_symbol(volatile VALUE *namep);
 
-#define RUBY_CONST_ID_CACHE(result, str)		\
-    {							\
+#define RUBY_CONST_ID_CACHE_NB(result, str)		\
 	static ID rb_intern_id_cache;			\
 	if (!rb_intern_id_cache)			\
 	    rb_intern_id_cache = rb_intern2((str), (long)strlen(str)); \
-	result rb_intern_id_cache;			\
+	result rb_intern_id_cache;
+#define RUBY_CONST_ID_CACHE(result, str)		\
+    {							\
+	RUBY_CONST_ID_CACHE_NB(result, str)		\
     }
 #define RUBY_CONST_ID(var, str) \
     do RUBY_CONST_ID_CACHE((var) =, (str)) while (0)
@@ -1844,7 +1846,7 @@ VALUE rb_check_symbol(volatile VALUE *namep);
  * since gcc-2.7.2.3 at least. */
 #define rb_intern(str) \
     (__builtin_constant_p(str) ? \
-        __extension__ (RUBY_CONST_ID_CACHE((ID), (str))) : \
+        __extension__ ({RUBY_CONST_ID_CACHE_NB((ID), (str))}) : \
         rb_intern(str))
 #define rb_intern_const(str) \
     (__builtin_constant_p(str) ? \
