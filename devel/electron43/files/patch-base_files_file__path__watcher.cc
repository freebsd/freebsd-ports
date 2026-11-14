--- base/files/file_path_watcher.cc.orig	2026-08-17 18:32:36 UTC
+++ base/files/file_path_watcher.cc
@@ -25,7 +25,7 @@ bool FilePathWatcher::RecursiveWatchAvailable() {
 bool FilePathWatcher::RecursiveWatchAvailable() {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) ||        \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_AIX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return true;
 #else
   // FSEvents isn't available on iOS.
