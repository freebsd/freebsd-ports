--- base/files/file_path_watcher_inotify.cc.orig	2026-08-17 18:32:36 UTC
+++ base/files/file_path_watcher_inotify.cc
@@ -45,6 +45,11 @@
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#endif
+
 namespace base {
 
 namespace {
@@ -151,6 +156,13 @@ class InotifyReader {
 
   Lock lock_;
 
+#if BUILDFLAG(IS_FREEBSD)
+  // Tracks files that are currently open, as (watch, name) pairs, to suppress
+  // duplicate IN_ATTRIB events on O_TRUNC. Entries are added on IN_OPEN and
+  // removed on IN_CLOSE_* and when the watch goes away. See OnInotifyEvent().
+  std::set<std::pair<Watch, FilePath::StringType>> open_files_ GUARDED_BY(lock_);
+#endif
+
   // Tracks which FilePathWatcherImpls to be notified on which watches.
   // The tracked FilePathWatcherImpl is keyed by raw pointers for fast look up
   // and mapped to a WatchEntry that is used to safely post a notification.
@@ -366,8 +378,15 @@ InotifyReader::Watch InotifyReader::AddWatch(const Fil
   ScopedBlockingCall scoped_blocking_call(FROM_HERE, BlockingType::WILL_BLOCK);
   const int watch_int =
       inotify_add_watch(inotify_fd_, path.value().c_str(),
+#if BUILDFLAG(IS_FREEBSD)
+                        // IN_OPEN is only requested on FreeBSD. It is needed
+                        // to populate open_files_. See OnInotifyEvent().
                         IN_ATTRIB | IN_CREATE | IN_DELETE | IN_CLOSE_WRITE |
+                            IN_MOVE | IN_OPEN | IN_ONLYDIR);
+#else
+                        IN_ATTRIB | IN_CREATE | IN_DELETE | IN_CLOSE_WRITE |
                             IN_MOVE | IN_ONLYDIR);
+#endif
   if (watch_int == -1) {
     return kInvalidWatch;
   }
@@ -396,6 +415,14 @@ void InotifyReader::RemoveWatch(Watch watch, FilePathW
   if (watcher_map.empty()) {
     watchers_.erase(watchers_it);
 
+#if BUILDFLAG(IS_FREEBSD)
+    // Drop the open-file records of this watch. Nothing else will clean them
+    // up, and stale entries could wrongly suppress IN_ATTRIB events if the
+    // watch descriptor is later reused.
+    std::erase_if(open_files_,
+                  [watch](const auto& item) { return item.first == watch; });
+#endif
+
     ScopedBlockingCall scoped_blocking_call(FROM_HERE,
                                             BlockingType::WILL_BLOCK);
     inotify_rm_watch(inotify_fd_, watch);
@@ -404,12 +431,64 @@ void InotifyReader::OnInotifyEvent(const inotify_event
 
 void InotifyReader::OnInotifyEvent(const inotify_event* event) {
   if (event->mask & IN_IGNORED) {
+#if BUILDFLAG(IS_FREEBSD)
+    // The watch was removed (explicitly or because the watched object went
+    // away), so forget the files tracked for it.
+    AutoLock auto_lock(lock_);
+    const Watch ignored_wd = static_cast<Watch>(event->wd);
+    std::erase_if(open_files_, [ignored_wd](const auto& item) {
+      return item.first == ignored_wd;
+    });
+#endif
     return;
   }
 
   FilePath::StringType child(event->len ? event->name : FILE_PATH_LITERAL(""));
   AutoLock auto_lock(lock_);
 
+#if BUILDFLAG(IS_FREEBSD)
+  // FreeBSD-specific filtering. Opening an existing file with O_TRUNC
+  // produces IN_ATTRIB followed by IN_CLOSE_WRITE, and both would be reported
+  // as a modification. To report it once, track which files are currently
+  // open (via IN_OPEN) and ignore IN_ATTRIB-only events for them. The later
+  // IN_CLOSE_WRITE is still forwarded.
+  const Watch wd = static_cast<Watch>(event->wd);
+  const auto file_key = std::make_pair(wd, child);
+
+  // Ignore IN_ISDIR when looking at the event type.
+  const uint32_t non_dir_mask = event->mask & ~IN_ISDIR;
+
+  // Record opened files (directories are not tracked). IN_OPEN is requested
+  // only for bookkeeping, so an event consisting solely of IN_OPEN is not
+  // forwarded to the watchers.
+  if (non_dir_mask & IN_OPEN) {
+    if (!(event->mask & IN_ISDIR)) {
+      open_files_.insert(file_key);
+    }
+    if ((non_dir_mask & ~IN_OPEN) == 0) {
+      return;
+    }
+  }
+
+  // Suppress a pure IN_ATTRIB event for a file that is currently open; it is
+  // the duplicate described above.
+  if ((non_dir_mask & IN_ATTRIB) && !(non_dir_mask & ~IN_ATTRIB)) {
+    if (open_files_.contains(file_key)) {
+      return;
+    }
+  }
+
+  // The file was closed, so stop tracking it. IN_CLOSE_NOWRITE is not
+  // requested by AddWatch(), but is handled defensively and swallowed since it
+  // does not indicate a change. IN_CLOSE_WRITE is still forwarded.
+  if (non_dir_mask & (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE)) {
+    open_files_.erase(file_key);
+    if ((non_dir_mask & ~IN_CLOSE_NOWRITE) == 0) {
+      return;
+    }
+  }
+#endif
+
   // In racing conditions, RemoveWatch() could grab `lock_` first and remove
   // the entry for `event->wd`.
   auto watchers_it = watchers_.find(static_cast<Watch>(event->wd));
@@ -916,6 +995,28 @@ size_t GetMaxNumberOfInotifyWatches() {
 #if BUILDFLAG(IS_FUCHSIA)
   // Fuchsia has no limit on the number of watches.
   return std::numeric_limits<int>::max();
+#elif BUILDFLAG(IS_FREEBSD)
+  // FreeBSD exposes the per-user watch limit via sysctl rather than /proc.
+  // As on Linux, divide by kExpectedFilePathWatchers so that several
+  // FilePathWatchers can coexist within the limit.
+  static const size_t max = []() -> size_t {
+    int max_number_of_inotify_watches = 0;
+    size_t len = sizeof(max_number_of_inotify_watches);
+    if (sysctlbyname("vfs.inotify.max_user_watches",
+                     &max_number_of_inotify_watches, &len, nullptr, 0) != 0) {
+      PLOG(ERROR) << "Failed to read sysctl vfs.inotify.max_user_watches";
+      return kDefaultInotifyMaxUserWatches / kExpectedFilePathWatchers;
+    }
+    if (len != sizeof(max_number_of_inotify_watches) ||
+        max_number_of_inotify_watches <= 0) {
+      LOG(ERROR) << "Unexpected value from sysctl vfs.inotify.max_user_watches";
+      return kDefaultInotifyMaxUserWatches / kExpectedFilePathWatchers;
+    }
+
+    return static_cast<size_t>(max_number_of_inotify_watches) /
+           kExpectedFilePathWatchers;
+  }();
+  return g_override_max_inotify_watches ? g_override_max_inotify_watches : max;
 #else
   static const size_t max = [] {
     size_t max_number_of_inotify_watches = 0u;
@@ -946,7 +1047,7 @@ FilePathWatcher::FilePathWatcher()
 FilePathWatcher::FilePathWatcher()
     : FilePathWatcher(std::make_unique<FilePathWatcherImpl>()) {}
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 // Put inside "BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)" because Android
 // includes file_path_watcher_linux.cc.
 
@@ -954,6 +1055,6 @@ bool FilePathWatcher::HasWatchesForTest() {
 bool FilePathWatcher::HasWatchesForTest() {
   return GetInotifyReader().HasWatches();
 }
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 }  // namespace base
