--- chrome/browser/extensions/chrome_app_deprecation.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/extensions/chrome_app_deprecation.cc
@@ -16,7 +16,7 @@ bool g_enable_chrome_apps_for_testing = false;
 bool g_enable_chrome_apps_for_testing = false;
 }  // namespace testing
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
