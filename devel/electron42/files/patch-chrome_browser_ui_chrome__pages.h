--- chrome/browser/ui/chrome_pages.h.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/ui/chrome_pages.h
@@ -37,7 +37,7 @@ enum class ConsentLevel;
 enum class ConsentLevel;
 }  // namespace signin
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace web_app {
 enum class AppSettingsPageEntryPoint;
 }  // namespace web_app
@@ -161,7 +161,7 @@ void ShowEnterpriseManagementPageInTabbedBrowser(
 void ShowEnterpriseManagementPageInTabbedBrowser(
     BrowserWindowInterface* browser);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Show chrome://app-settings/<app-id> page.
 void ShowWebAppSettings(BrowserWindowInterface* browser,
                         const std::string& app_id,
