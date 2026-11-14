--- content/browser/file_system_access/file_path_watcher/file_path_watcher.h.orig	2026-08-17 18:32:36 UTC
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher.h
@@ -125,7 +125,7 @@ class CONTENT_EXPORT FilePathWatcher {
     Type type = Type::kNonRecursive;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     // The callback will return the full path to a changed file instead of
     // the watched path supplied as |path| when Watch is called.
     // So the full path can be different from the watched path when a folder is
@@ -225,10 +225,10 @@ class CONTENT_EXPORT FilePathWatcher {
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
