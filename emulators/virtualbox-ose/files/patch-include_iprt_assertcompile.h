--- include/iprt/assertcompile.h.orig	2018-01-15 14:49:42 UTC
+++ include/iprt/assertcompile.h
@@ -104,7 +104,11 @@ RT_C_DECLS_END
  * @param   expr    Expression which should be true.
  */
 #ifdef RTASSERT_HAVE_STATIC_ASSERT
-# define AssertCompile(expr)    static_assert(!!(expr), #expr)
+#  ifdef __cplusplus
+#    define AssertCompile(expr) static_assert(!!(expr), #expr)
+#  else
+#    define AssertCompile(expr) _Static_assert(!!(expr), #expr)
+#  endif
 #else
 # define AssertCompile(expr)    AssertCompileNS(expr)
 #endif
