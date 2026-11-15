--- content/browser/file_system_access/file_path_watcher/file_path_watcher_unittest.cc.orig	2026-11-10 20:19:00 UTC
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher_unittest.cc
@@ -61,7 +61,7 @@
 #include "base/files/file_descriptor_watcher_posix.h"
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 #include <sys/inotify.h>
 #include <sys/socket.h>
 #include <unistd.h>
@@ -77,7 +77,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 // Queue packets before running the reader so read boundaries and the readiness
 // of the next batch do not depend on filesystem or thread scheduling.
 class InotifyReaderTest : public testing::Test {
@@ -152,12 +152,12 @@ TEST_F(InotifyReaderTest, DoesNotPairMovesAcrossBuffer
   EXPECT_THAT(events_, testing::ElementsAre(IN_MOVED_FROM, IN_MOVED_TO));
   EXPECT_THAT(moves_, testing::IsEmpty());
 }
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 base::AtomicSequenceNumber g_next_delegate_id;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FREEBSD)
 // inotify fires two events - one for each file creation + modification.
 constexpr size_t kExpectedEventsForNewFileWrite = 2;
 #else
@@ -166,13 +166,13 @@ constexpr size_t kExpectedEventsForNewFileWrite = 1;
 
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
@@ -274,7 +274,7 @@ inline constexpr auto HasMovedFromPath = [](const base
       testing::Field(&FilePathWatcher::ChangeInfo::moved_from_path, path));
 };
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
 inline constexpr auto HasNoMovedFromPath = []() {
   return testing::Field(
       &Event::change_info,
@@ -290,7 +290,7 @@ inline constexpr auto IsType =
     };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FREEBSD)
 inline constexpr auto IsFile = []() {
   return testing::Field(
       &Event::change_info,
@@ -305,7 +305,7 @@ inline constexpr auto IsDirectory = []() {
 };
 #endif
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FREEBSD)
 inline constexpr auto IsUnknownPathType = []() {
   return testing::Field(
       &Event::change_info,
@@ -337,7 +337,7 @@ inline constexpr auto IsDirectory = []() {
 };
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 inline constexpr auto IsDeletedFile = IsFile;
 inline constexpr auto IsDeletedDirectory = IsDirectory;
 
@@ -387,7 +387,7 @@ inline constexpr auto ModifiedMatcher = [](base::FileP
 };
 #endif
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 // `EventExpecter`s can be implemented to provide a more convenient abstraction
 // to tests than building their own `EventListMatcher`s. An `EventExpecter` can
@@ -1377,13 +1377,13 @@ TEST_F(FilePathWatcherTest, DisappearingDirectory) {
 
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
@@ -1787,7 +1787,7 @@ TEST_F(FilePathWatcherTest, NoEventWhenFileAttributesC
 }
 #endif  // !BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // Verify that creating a symlink is caught.
 TEST_F(FilePathWatcherTest, CreateLink) {
@@ -2249,10 +2249,10 @@ TEST_F(FilePathWatcherTest, InotifyLimitInUpdateRecurs
   }
 }
 
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // TODO(fxbug.dev/60109): enable BUILDFLAG(IS_FUCHSIA) when implemented.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 TEST_F(FilePathWatcherTest, ReturnFullPath_RecursiveInRootFolder) {
   FilePathWatcher directory_watcher;
@@ -2468,7 +2468,7 @@ TEST_F(FilePathWatcherTest, ReturnWatchedPath_NonRecur
 }
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 namespace {
 
@@ -3174,7 +3174,7 @@ TEST_P(FilePathWatcherWithChangeInfoTest, MoveChild) {
   subdir_delegate.RunUntilEventsMatch(subdir_event_expecter);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 TEST_P(FilePathWatcherWithChangeInfoTest, MoveParentWithTargetTypeChanged) {
   base::FilePath parent_dir(temp_dir_.GetPath().AppendASCII("parent"));
   base::FilePath moved_parent_dir(
@@ -3224,7 +3224,7 @@ TEST_P(FilePathWatcherWithChangeInfoTest, MoveParentWi
   delegate.RunUntilEventsMatch(deleted_directory_event_expecter);
 }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
 
 TEST_P(FilePathWatcherWithChangeInfoTest, MoveChildWithinWatchedScope) {
   base::FilePath dir(temp_dir_.GetPath().AppendASCII("dir"));
@@ -3345,7 +3345,7 @@ TEST_P(FilePathWatcherWithChangeInfoTest, NoEventWhenF
 }
 #endif  // !BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 TEST_P(FilePathWatcherWithChangeInfoTest, CreateLink) {
   EventExpecterWithChangeInfo event_expecter;
 
@@ -3608,7 +3608,7 @@ TEST_P(FilePathWatcherWithChangeInfoTest, LinkedDirect
   ASSERT_TRUE(DeleteFile(file));
   delegate.RunUntilEventsMatch(matcher);
 }
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 TEST_P(FilePathWatcherWithChangeInfoTest, CreatedFileInDirectory) {
@@ -4076,7 +4076,7 @@ TEST_F(FilePathWatcherTest, UseDummyChangeInfoIfNotSup
 }
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+        // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
 
 #if BUILDFLAG(IS_WIN)
 
