--- content/browser/file_system_access/file_system_access_watcher_manager_unittest.cc.orig	2026-08-17 18:32:36 UTC
+++ content/browser/file_system_access/file_system_access_watcher_manager_unittest.cc
@@ -69,22 +69,22 @@ bool ReportsModifiedPathForLocalObservations() {
 
 bool ReportsModifiedPathForLocalObservations() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
   return true;
 #else
   return false;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||
-        // BUILDFLAG(IS_WIN)
+        // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FREEBSD)
 }
 
 bool ReportsChangeInfoForLocalObservations() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
   return true;
 #else
   return false;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||
-        // BUILDFLAG(IS_MAC)
+        // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FREEBSD)
 }
 
 #endif  // !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FUCHSIA) &&
