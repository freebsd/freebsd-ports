--- content/browser/file_system_access/file_path_watcher/file_path_watcher_inotify.cc.orig	2026-11-10 20:19:00 UTC
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher_inotify.cc
@@ -50,6 +50,11 @@
 #include "content/browser/file_system_access/file_path_watcher/file_path_watcher.h"
 #include "content/browser/file_system_access/file_path_watcher/file_path_watcher_histogram.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#endif
+
 namespace content {
 
 namespace {
@@ -1415,6 +1420,27 @@ size_t GetMaxNumberOfInotifyWatches() {
 #if BUILDFLAG(IS_FUCHSIA)
   // Fuchsia has no limit on the number of watches.
   return std::numeric_limits<int>::max();
+#elif BUILDFLAG(IS_FREEBSD)
+  // FreeBSD exposes the per-user watch limit via sysctl rather than /proc.
+  // The value is read once and cached. If it cannot be read or is unusable,
+  // fall back to kDefaultInotifyMaxUserWatches, like the /proc path below.
+  static const size_t max = []() -> size_t {
+    int max_number_of_inotify_watches = 0;
+    size_t len = sizeof(max_number_of_inotify_watches);
+    if (sysctlbyname("vfs.inotify.max_user_watches",
+                     &max_number_of_inotify_watches, &len, nullptr, 0) != 0) {
+      PLOG(ERROR) << "Failed to read sysctl vfs.inotify.max_user_watches";
+      return kDefaultInotifyMaxUserWatches;
+    }
+    if (len != sizeof(max_number_of_inotify_watches) ||
+        max_number_of_inotify_watches <= 0) {
+      LOG(ERROR) << "Unexpected value from sysctl vfs.inotify.max_user_watches";
+      return kDefaultInotifyMaxUserWatches;
+    }
+
+    return static_cast<size_t>(max_number_of_inotify_watches);
+  }();
+  return max;
 #else
   static const size_t max = []() {
     size_t max_number_of_inotify_watches = 0u;
@@ -1450,7 +1476,7 @@ size_t FilePathWatcher::GetQuotaLimitImpl() {
   return GetQuotaLimitFromSystemLimit(GetMaxNumberOfInotifyWatches());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 // Put inside "BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)" because Android
 // includes file_path_watcher_linux.cc.
 
@@ -1458,6 +1484,6 @@ bool FilePathWatcher::HasWatchesForTest() {
 bool FilePathWatcher::HasWatchesForTest() {
   return GetInotifyReader().HasWatches();
 }
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 }  // namespace content
