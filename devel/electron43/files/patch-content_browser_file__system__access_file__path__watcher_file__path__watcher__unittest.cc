--- content/browser/file_system_access/file_path_watcher/file_path_watcher_unittest.cc.orig	2026-08-17 18:32:36 UTC
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher_unittest.cc
@@ -57,7 +57,7 @@
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 #include "base/format_macros.h"
 #include "content/browser/file_system_access/file_path_watcher/file_path_watcher_inotify.h"
 #endif
@@ -69,7 +69,7 @@ base::AtomicSequenceNumber g_next_delegate_id;
 base::AtomicSequenceNumber g_next_delegate_id;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FREEBSD)
 // inotify fires two events - one for each file creation + modification.
 constexpr size_t kExpectedEventsForNewFileWrite = 2;
 #else
@@ -78,13 +78,13 @@ constexpr size_t kExpectedEventsForNewFileWrite = 1;
 
 #define CHANGE_INFO_SUPPORTED                                               \
   BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-      BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+      BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
 
 #if CHANGE_INFO_SUPPORTED
 // Only the inotify FilePathWatcher's usage can change while watching a file
 // entry. Other FilePathWatchers have a constant amount of usage.
 constexpr bool kUsageCanChange =
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID);
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD);
 #endif
 
 enum class ExpectedEventsSinceLastWait { kNone, kSome };
@@ -186,7 +186,7 @@ inline constexpr auto HasMovedFromPath = [](const base
       testing::Field(&FilePathWatcher::ChangeInfo::moved_from_path, path));
 };
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
 inline constexpr auto HasNoMovedFromPath = []() {
   return testing::Field(
       &Event::change_info,
@@ -202,7 +202,7 @@ inline constexpr auto IsType =
     };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FREEBSD)
 inline constexpr auto IsFile = []() {
   return testing::Field(
       &Event::change_info,
@@ -217,7 +217,7 @@ inline constexpr auto IsDirectory = []() {
 };
 #endif
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FREEBSD)
 inline constexpr auto IsUnknownPathType = []() {
   return testing::Field(
       &Event::change_info,
@@ -249,7 +249,7 @@ inline constexpr auto IsDirectory = []() {
 };
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 inline constexpr auto IsDeletedFile = IsFile;
 inline constexpr auto IsDeletedDirectory = IsDirectory;
 
@@ -300,7 +300,7 @@ inline constexpr auto ModifiedMatcher = [](base::FileP
 };
 #endif
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 // `EventExpecter`s can be implemented to provide a more convenient abstraction
 // to tests than building their own `EventListMatcher`s. An `EventExpecter` can
@@ -1290,13 +1290,13 @@ TEST_F(FilePathWatcherTest, DisappearingDirectory) {
 
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
 #endif
@@ -1700,7 +1700,7 @@ TEST_F(FilePathWatcherTest, NoEventWhenFileAttributesC
 }
 #endif  // !BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // Verify that creating a symlink is caught.
 TEST_F(FilePathWatcherTest, CreateLink) {
@@ -2162,10 +2162,10 @@ TEST_F(FilePathWatcherTest, InotifyLimitInUpdateRecurs
   }
 }
 
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // TODO(fxbug.dev/60109): enable BUILDFLAG(IS_FUCHSIA) when implemented.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 TEST_F(FilePathWatcherTest, ReturnFullPath_RecursiveInRootFolder) {
   FilePathWatcher directory_watcher;
@@ -2381,7 +2381,7 @@ TEST_F(FilePathWatcherTest, ReturnWatchedPath_NonRecur
 }
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 namespace {
 
@@ -3206,7 +3206,7 @@ TEST_P(FilePathWatcherWithChangeInfoTest, NoEventWhenF
 }
 #endif  // !BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 TEST_P(FilePathWatcherWithChangeInfoTest, CreateLink) {
   EventExpecterWithChangeInfo event_expecter;
 
@@ -3431,7 +3431,7 @@ TEST_P(FilePathWatcherWithChangeInfoTest, LinkedDirect
   ASSERT_TRUE(DeleteFile(file));
   delegate.RunUntilEventsMatch(matcher);
 }
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 TEST_P(FilePathWatcherWithChangeInfoTest, CreatedFileInDirectory) {
@@ -3899,6 +3899,6 @@ TEST_F(FilePathWatcherTest, UseDummyChangeInfoIfNotSup
 }
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
 
 }  // namespace content
