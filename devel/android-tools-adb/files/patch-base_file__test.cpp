--- base/file_test.cpp.orig	2017-06-20 10:50:27 UTC
+++ base/file_test.cpp
@@ -52,12 +52,20 @@ TEST(file, ReadFileToString_WriteStringToFile_symlink)
   ASSERT_EQ(0, unlink(link.path));
   ASSERT_EQ(0, symlink(target.path, link.path));
   ASSERT_FALSE(android::base::WriteStringToFile("foo", link.path, false));
+#ifdef __linux__
   ASSERT_EQ(ELOOP, errno);
+#else
+  ASSERT_EQ(EMLINK, errno);
+#endif
   ASSERT_TRUE(android::base::WriteStringToFile("foo", link.path, true));
 
   std::string s;
   ASSERT_FALSE(android::base::ReadFileToString(link.path, &s));
+#ifdef __linux__
   ASSERT_EQ(ELOOP, errno);
+#else
+  ASSERT_EQ(EMLINK, errno);
+#endif
   ASSERT_TRUE(android::base::ReadFileToString(link.path, &s, true));
   ASSERT_EQ("foo", s);
 }
@@ -131,6 +139,7 @@ TEST(file, RemoveFileIfExist) {
 
 TEST(file, Readlink) {
 #if !defined(_WIN32)
+#ifdef __linux__
   // Linux doesn't allow empty symbolic links.
   std::string min("x");
   // ext2 and ext4 both have PAGE_SIZE limits.
@@ -139,6 +148,10 @@ TEST(file, Readlink) {
   // in current kernels (and marlin/sailfish where we're seeing this
   // failure are still on 3.18, far from current). http://b/33306057.
   std::string max(static_cast<size_t>(4096 - 2 - 1 - 1), 'x');
+#else
+  std::string min("");
+  std::string max(static_cast<size_t>(1024 - 1), 'x');
+#endif
 
   TemporaryDir td;
   std::string min_path{std::string(td.path) + "/" + "min"};
