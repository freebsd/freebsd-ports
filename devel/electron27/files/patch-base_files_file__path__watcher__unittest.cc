--- base/files/file_path_watcher_unittest.cc.orig	2023-10-19 19:57:58 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -586,7 +586,7 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
   }
   delegate.RunUntilEventsMatch(event_expecter);
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && BUILDFLAG(IS_BSD)
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   // Mac implementation does not detect files modified in a directory.
   // TODO(https://crbug.com/1432064): Expect that no events are fired on Mac.
@@ -1525,7 +1525,7 @@ namespace {
 
 enum Permission { Read, Write, Execute };
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -1559,7 +1559,7 @@ bool ChangeFilePermissions(const FilePath& path, Permi
 
 }  // namespace
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) && BUILDFLAG(IS_BSD)
 // Linux implementation of FilePathWatcher doesn't catch attribute changes.
 // http://crbug.com/78043
 // Windows implementation of FilePathWatcher catches attribute changes that
