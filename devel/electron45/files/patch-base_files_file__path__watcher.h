--- base/files/file_path_watcher.h.orig	2026-11-10 20:19:00 UTC
+++ base/files/file_path_watcher.h
@@ -106,7 +106,7 @@ class BASE_EXPORT FilePathWatcher {
     Type type = Type::kNonRecursive;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // The callback will return the full path to a changed file instead of
     // the watched path supplied as |path| when Watch is called.
     // So the full path can be different from the watched path when a folder is
@@ -200,10 +200,10 @@ class BASE_EXPORT FilePathWatcher {
   // Returns true if the platform and OS version support recursive watches.
   static bool RecursiveWatchAvailable();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
   // Whether there are outstanding inotify watches.
   static bool HasWatchesForTest();
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
   // Starts watching |path| (and its descendants if |type| is kRecursive) for
   // changes. |callback| will be run on the caller's sequence to report such
