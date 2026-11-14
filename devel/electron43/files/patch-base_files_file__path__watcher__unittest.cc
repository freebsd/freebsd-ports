--- base/files/file_path_watcher_unittest.cc.orig	2026-08-17 18:32:36 UTC
+++ base/files/file_path_watcher_unittest.cc
@@ -49,7 +49,7 @@
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 #include "base/files/file_path_watcher_inotify.h"
 #include "base/format_macros.h"
 #endif
@@ -61,7 +61,7 @@ AtomicSequenceNumber g_next_delegate_id;
 AtomicSequenceNumber g_next_delegate_id;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FREEBSD)
 // inotify fires two events - one for each file creation + modification.
 constexpr size_t kExpectedEventsForNewFileWrite = 2;
 #else
@@ -169,7 +169,7 @@ inline constexpr auto IsType =
           testing::Field(&FilePathWatcher::ChangeInfo::change_type,
                          change_type));
     };
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 inline constexpr auto IsFile = [] {
   return testing::Field(
       &Event::change_info,
@@ -190,7 +190,7 @@ inline constexpr auto IsUnknownPathType = [] {
                      FilePathWatcher::FilePathType::kUnknown));
 };
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 // Enables an accumulative, add-as-you-go pattern for expecting events:
 //   - Do something that should fire `event1` on `delegate`
@@ -859,13 +859,13 @@ TEST_F(FilePathWatcherTest, DisappearingDirectory) {
 
   ASSERT_TRUE(DeletePathRecursively(dir));
   event_expecter.AddExpectedEventForPath(file);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
   // TODO(crbug.com/40263766): Figure out why this may fire two events on
   // inotify. Only the file is being watched, so presumably there should only be
   // one deletion event.
   event_expecter.AddExpectedEventForPath(file);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
   delegate.RunUntilEventsMatch(event_expecter);
 }
 
@@ -1034,13 +1034,13 @@ TEST_F(FilePathWatcherTest, RecursiveWatch) {
   FilePath subdir2b(subdir.AppendASCII("subdir2b"));
   Move(subdir2, subdir2b);
   event_expecter.AddExpectedEventForPath(dir);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
   // inotify generates separate IN_MOVED_TO and IN_MOVED_FROM events for a
   // rename. Since both the source and destination are within the scope of this
   // watch, both events should be received.
   event_expecter.AddExpectedEventForPath(dir);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
   delegate.RunUntilEventsMatch(event_expecter);
 
 // Mac and Win don't generate events for Touch.
@@ -1233,7 +1233,7 @@ TEST_F(FilePathWatcherTest, FileAttributesChanged) {
   delegate.RunUntilEventsMatch(event_expecter);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // Verify that creating a symlink is caught.
 TEST_F(FilePathWatcherTest, CreateLink) {
@@ -1646,10 +1646,10 @@ TEST_F(FilePathWatcherTest, InotifyLimitInUpdateRecurs
   }
 }
 
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // TODO(fxbug.dev/60109): enable BUILDFLAG(IS_FUCHSIA) when implemented.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 TEST_F(FilePathWatcherTest, ReturnFullPath_RecursiveInRootFolder) {
   FilePathWatcher directory_watcher;
@@ -1860,7 +1860,7 @@ TEST_F(FilePathWatcherTest, ReturnWatchedPath_NonRecur
 }
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 namespace {
 
@@ -2020,7 +2020,7 @@ TEST_F(FilePathWatcherTest, TrivialDirMove) {
 
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 // TODO(crbug.com/40263777): Ideally most all of the tests above would be
 // parameterized in this way.
 // TODO(crbug.com/40260973): ChangeInfo is currently only supported by
@@ -3022,6 +3022,6 @@ TEST_F(FilePathWatcherTest, UseDummyChangeInfoIfNotSup
 }
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 }  // namespace base
