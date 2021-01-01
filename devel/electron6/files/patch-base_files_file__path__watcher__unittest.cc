--- base/files/file_path_watcher_unittest.cc.orig	2019-09-10 11:13:31 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -436,7 +436,7 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
   VLOG(1) << "Waiting for file1 creation";
   ASSERT_TRUE(WaitForEvents());
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   // Mac implementation does not detect files modified in a directory.
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   VLOG(1) << "Waiting for file1 modification";
