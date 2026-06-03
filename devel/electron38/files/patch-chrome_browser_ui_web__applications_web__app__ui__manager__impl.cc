--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -564,7 +564,7 @@ void WebAppUiManagerImpl::MaybeShowIPHPromoForAppsLaun
     Browser* browser,
     Profile* profile,
     const std::string& app_id) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForWebApps(profile);
   CHECK(provider);
 
@@ -793,7 +793,7 @@ void WebAppUiManagerImpl::ClearWebAppSiteDataIfNeeded(
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 const base::Feature& GetPromoFeatureEngagementFromBrowser(
     const Browser* browser) {
