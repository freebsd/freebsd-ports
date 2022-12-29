--- test/gjs-tests.cpp.orig	2022-08-08 05:05:12 UTC
+++ test/gjs-tests.cpp
@@ -939,7 +939,7 @@ static void gjstest_test_args_set_get_unset() {
     assert_equal(arg.v_uint64, random_uint64);
     assert_equal(gjs_arg_get<uint64_t>(&arg), random_uint64);
 
-    char32_t random_char32 = get_random_number<char32_t>();
+    char32_t random_char32 = static_cast<char32_t>(get_random_number<uint32_t>());
     gjs_arg_set(&arg, random_char32);
     assert_equal(static_cast<char32_t>(arg.v_uint32), random_char32);
     assert_equal(gjs_arg_get<char32_t>(&arg), random_char32);
