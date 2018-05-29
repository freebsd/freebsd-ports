--- path_utils/path_utils_ut.c.orig	2018-05-29 08:04:46 UTC
+++ path_utils/path_utils_ut.c
@@ -62,7 +62,7 @@ START_TEST(test_dirname)
     fail_unless_str_equal(p, "//foo");
 
     fail_unless(get_dirname(p, PATH_MAX, "//foo//") == SUCCESS);
-    fail_unless_str_equal(p, "//");
+    fail_unless_str_equal(p, "/");
 
     fail_unless(get_dirname(p, PATH_MAX, "foo//bar") == SUCCESS);
     fail_unless_str_equal(p, "foo");
