--- chrome/browser/ui/chrome_pages.cc.orig	2022-05-25 04:00:50 UTC
+++ chrome/browser/ui/chrome_pages.cc
@@ -561,7 +561,7 @@ void ShowBrowserSigninOrSettings(Browser* browser,
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 void ShowWebAppSettings(Browser* browser,
                         const std::string& app_id,
                         web_app::AppSettingsPageEntryPoint entry_point) {
