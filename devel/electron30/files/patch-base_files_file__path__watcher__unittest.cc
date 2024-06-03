--- base/files/file_path_watcher_unittest.cc.orig	2024-02-21 00:20:30 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -847,7 +847,7 @@ TEST_F(FilePathWatcherTest, WatchDirectory) {
   }
   delegate.RunUntilEventsMatch(event_expecter);
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && BUILDFLAG(IS_BSD)
   ASSERT_TRUE(WriteFile(file1, "content v2"));
   // Mac implementation does not detect files modified in a directory.
   // TODO(https://crbug.com/1432064): Expect that no events are fired on Mac.
@@ -1783,7 +1783,7 @@ enum Permission { Read, Write, Execute };
 
 enum Permission { Read, Write, Execute };
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
 bool ChangeFilePermissions(const FilePath& path, Permission perm, bool allow) {
   struct stat stat_buf;
 
@@ -1817,7 +1817,7 @@ bool ChangeFilePermissions(const FilePath& path, Permi
 
 }  // namespace
 
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) && BUILDFLAG(IS_BSD)
 // Linux implementation of FilePathWatcher doesn't catch attribute changes.
 // http://crbug.com/78043
 // Windows implementation of FilePathWatcher catches attribute changes that
