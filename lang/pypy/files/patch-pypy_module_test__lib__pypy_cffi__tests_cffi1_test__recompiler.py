--- pypy/module/test_lib_pypy/cffi_tests/cffi1/test_recompiler.py.orig	2017-10-30 18:06:00 UTC
+++ pypy/module/test_lib_pypy/cffi_tests/cffi1/test_recompiler.py
@@ -2271,7 +2271,7 @@ def test_char16_char32_type(no_cpp=False
         char32_t foo_4bytes(char32_t);
     """)
     lib = verify(ffi, "test_char16_char32_type" + no_cpp * "_nocpp", """
-    #if !defined(__cplusplus) || __cplusplus < 201103L
+    #if !defined(__cplusplus) || (!defined(_LIBCPP_VERSION) && __cplusplus < 201103L)
     typedef uint_least16_t char16_t;
     typedef uint_least32_t char32_t;
     #endif
