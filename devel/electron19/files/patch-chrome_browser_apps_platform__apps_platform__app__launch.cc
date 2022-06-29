--- chrome/browser/apps/platform_apps/platform_app_launch.cc.orig	2022-05-25 04:00:47 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.cc
@@ -19,7 +19,7 @@
 #include "extensions/common/extension.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_window.h"
@@ -124,7 +124,7 @@ bool OpenExtensionApplicationTab(Profile* profile, con
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 bool OpenDeprecatedApplicationPrompt(Profile* profile,
                                      const std::string& app_id) {
   if (!extensions::IsExtensionUnsupportedDeprecatedApp(profile, app_id))
