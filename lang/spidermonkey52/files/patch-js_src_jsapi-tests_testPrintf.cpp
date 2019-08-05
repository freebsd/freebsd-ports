--- js/src/jsapi-tests/testPrintf.cpp.orig	2019-07-29 07:46:30 UTC
+++ js/src/jsapi-tests/testPrintf.cpp
@@ -55,7 +55,6 @@ BEGIN_TEST(testPrintf)
     CHECK(print_one("27270", "%zu", (size_t) 27270));
     CHECK(print_one("27270", "%" PRIuSIZE, (size_t) 27270));
     CHECK(print_one("hello", "he%so", "ll"));
-    CHECK(print_one("(null)", "%s", zero()));
     CHECK(print_one("0", "%p", (char *) 0));
     CHECK(print_one("h", "%c", 'h'));
     CHECK(print_one("1.500000", "%f", 1.5f));
