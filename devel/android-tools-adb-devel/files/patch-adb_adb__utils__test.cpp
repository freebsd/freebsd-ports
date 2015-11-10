--- adb/adb_utils_test.cpp.orig	2015-11-07 17:05:12 UTC
+++ adb/adb_utils_test.cpp
@@ -194,7 +194,7 @@ TEST(adb_utils, parse_host_and_port) {
 }
 
 void test_mkdirs(const std::string basepath) {
-  EXPECT_TRUE(mkdirs(basepath));
+  EXPECT_TRUE(mkdirs(adb_dirname(basepath)));
   EXPECT_NE(-1, adb_creat(basepath.c_str(), 0600));
   EXPECT_FALSE(mkdirs(basepath + "/subdir/"));
 }
