--- base/files/file_util_unittest.cc.orig	2022-05-25 04:00:43 UTC
+++ base/files/file_util_unittest.cc
@@ -3523,7 +3523,7 @@ TEST_F(FileUtilTest, ReadFileToStringWithNamedPipe) {
 }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 TEST_F(FileUtilTest, ReadFileToStringWithProcFileSystem) {
   FilePath file_path("/proc/cpuinfo");
   std::string data = "temp";
@@ -4239,7 +4239,7 @@ TEST(FileUtilMultiThreadedTest, MultiThreadedTempFiles
                 NULL);
 #else
     size_t bytes_written =
-        ::write(::fileno(output_file.get()), content.c_str(), content.length());
+        ::write(fileno(output_file.get()), content.c_str(), content.length());
 #endif
     EXPECT_EQ(content.length(), bytes_written);
     ::fflush(output_file.get());
