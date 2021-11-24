--- chrome/browser/ui/startup/startup_browser_creator_impl.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/ui/startup/startup_browser_creator_impl.cc
@@ -106,7 +106,7 @@ namespace {
 bool ShouldRestoreApps(bool is_post_restart) {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return true;
-#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // TODO(stahon@microsoft.com)
   // Even when app restores are enabled on mac, don't actually restore apps
   // because they do not restore correctly. http://crbug.com/1194201
