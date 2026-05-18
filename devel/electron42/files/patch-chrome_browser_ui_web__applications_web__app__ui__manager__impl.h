--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -246,7 +246,7 @@ class WebAppUiManagerImpl : public BrowserCollectionOb
       UninstallCompleteCallback uninstall_complete_callback,
       webapps::UninstallResultCode uninstall_code);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(Browser* browser,
                                                    const webapps::AppId& app_id,
                                                    bool is_activated);
