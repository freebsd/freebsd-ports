--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/ui/startup/startup_browser_creator.cc
@@ -125,7 +125,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "chrome/browser/web_applications/components/url_handler_launch_params.h"
 #include "chrome/browser/web_applications/components/url_handler_manager_impl.h"
 #include "third_party/blink/public/common/features.h"
@@ -510,7 +510,7 @@ bool MaybeLaunchApplication(
 }
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 // If |command_line| contains a single URL argument and that URL matches URL
 // handling registration from installed web apps, show app options to user and
 // launch one if accepted.
@@ -1061,7 +1061,7 @@ bool StartupBrowserCreator::ProcessCmdLineImpl(
 
   // Web app URL handling.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   if (MaybeLaunchUrlHandlerWebApp(command_line, cur_dir,
                                   std::make_unique<LaunchModeRecorder>())) {
     return true;
