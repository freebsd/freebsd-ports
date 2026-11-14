--- content/browser/file_system_access/file_path_watcher/file_path_watcher.cc.orig	2026-08-17 18:32:36 UTC
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher.cc
@@ -59,7 +59,7 @@ bool FilePathWatcher::RecursiveWatchAvailable() {
 // static
 bool FilePathWatcher::RecursiveWatchAvailable() {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   // FSEvents isn't available on iOS.
