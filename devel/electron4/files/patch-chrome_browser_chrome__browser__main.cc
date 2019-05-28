--- chrome/browser/chrome_browser_main.cc.orig	2019-03-15 06:37:01 UTC
+++ chrome/browser/chrome_browser_main.cc
@@ -216,7 +216,7 @@
 #include "chromeos/settings/cros_settings_names.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/first_run/upgrade_util_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -257,7 +257,7 @@
 #endif  // defined(OS_WIN)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "chrome/browser/metrics/desktop_session_duration/desktop_session_duration_tracker.h"
 #endif
 
@@ -1287,10 +1287,10 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
   }
 #endif  // !defined(OS_ANDROID) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX)
   // Set the product channel for crash reports.
   breakpad::SetChannelCrashKey(chrome::GetChannelName());
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX)
 
 #if defined(OS_MACOSX)
   // Get the Keychain API to register for distributed notifications on the main
@@ -1314,7 +1314,7 @@ int ChromeBrowserMainParts::PreCreateThreadsImpl() {
   }
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD))
   metrics::DesktopSessionDurationTracker::Initialize();
 #endif
   metrics::RendererUptimeTracker::Initialize();
