--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -611,7 +611,7 @@ void WebAppUiManagerImpl::MaybeShowIPHPromoForAppsLaun
     Browser* browser,
     Profile* profile,
     const std::string& app_id) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForWebApps(profile);
   CHECK(provider);
 
@@ -829,7 +829,7 @@ void WebAppUiManagerImpl::ClearWebAppSiteDataIfNeeded(
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 const base::Feature& GetPromoFeatureEngagementFromBrowser(
     const BrowserWindowInterface* browser) {
