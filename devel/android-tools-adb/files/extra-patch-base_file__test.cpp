commit cf168a8 + cbf26b7
Author: Spencer Low <CompareAndSwap@gmail.com>
Date:   Mon Aug 3 20:43:24 2015 -0700

    libbase_test: win32: get some tests working
[...]
     - enh's edit to my previous change deleted a test that used
       /proc/version, but I think another test was missed. Merge that test into
       another.

--- base/file_test.cpp.orig	2015-08-27 08:07:53 UTC
+++ base/file_test.cpp
@@ -34,16 +34,7 @@ TEST(file, ReadFileToString_ENOENT) {
   EXPECT_EQ("", s);  // s was cleared.
 }
 
-TEST(file, ReadFileToString_success) {
-  std::string s("hello");
-  ASSERT_TRUE(android::base::ReadFileToString("/proc/version", &s)) << errno;
-  EXPECT_GT(s.length(), 6U);
-  EXPECT_EQ('\n', s[s.length() - 1]);
-  s[5] = 0;
-  EXPECT_STREQ("Linux", s.c_str());
-}
-
-TEST(file, WriteStringToFile) {
+TEST(file, ReadFileToString_WriteStringToFile) {
   TemporaryFile tf;
   ASSERT_TRUE(tf.fd != -1);
   ASSERT_TRUE(android::base::WriteStringToFile("abc", tf.filename)) << errno;
@@ -80,27 +71,20 @@ TEST(file, WriteStringToFd) {
   EXPECT_EQ("abc", s);
 }
 
-TEST(file, ReadFully) {
-  int fd = open("/proc/version", O_RDONLY);
-  ASSERT_NE(-1, fd) << strerror(errno);
-
-  char buf[1024];
-  memset(buf, 0, sizeof(buf));
-  ASSERT_TRUE(android::base::ReadFully(fd, buf, 5));
-  ASSERT_STREQ("Linux", buf);
-
-  ASSERT_EQ(0, lseek(fd, 0, SEEK_SET)) << strerror(errno);
-
-  ASSERT_FALSE(android::base::ReadFully(fd, buf, sizeof(buf)));
-
-  close(fd);
-}
-
 TEST(file, WriteFully) {
   TemporaryFile tf;
   ASSERT_TRUE(tf.fd != -1);
   ASSERT_TRUE(android::base::WriteFully(tf.fd, "abc", 3));
+
+  ASSERT_EQ(0, lseek(tf.fd, 0, SEEK_SET)) << errno;
+
   std::string s;
-  ASSERT_TRUE(android::base::ReadFileToString(tf.filename, &s)) << errno;
+  s.resize(3);
+  ASSERT_TRUE(android::base::ReadFully(tf.fd, &s[0], s.size())) << errno;
   EXPECT_EQ("abc", s);
+
+  ASSERT_EQ(0, lseek(tf.fd, 0, SEEK_SET)) << errno;
+
+  s.resize(1024);
+  ASSERT_FALSE(android::base::ReadFully(tf.fd, &s[0], s.size()));
 }
