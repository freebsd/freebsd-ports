--- chrome/browser/ui/chrome_pages.cc.orig	2023-05-25 00:41:45 UTC
+++ chrome/browser/ui/chrome_pages.cc
@@ -69,7 +69,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/web_app_utils.h"
 #endif
 
@@ -663,7 +663,7 @@ void ShowBrowserSigninOrSettings(Browser* browser,
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 void ShowWebAppSettings(Browser* browser,
                         const std::string& app_id,
                         web_app::AppSettingsPageEntryPoint entry_point) {
