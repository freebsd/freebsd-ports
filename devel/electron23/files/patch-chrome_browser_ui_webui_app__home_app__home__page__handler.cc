--- chrome/browser/ui/webui/app_home/app_home_page_handler.cc.orig	2023-02-01 18:43:13 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.cc
@@ -144,7 +144,7 @@ void AppHomePageHandler::InstallOsHooks(const web_app:
       web_app->CanUserUninstallWebApp();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = true;
 #else
   options.os_hooks[web_app::OsHookType::kUrlHandlers] = false;
@@ -276,7 +276,7 @@ void AppHomePageHandler::FillExtensionInfoList(
     bool is_deprecated_app = false;
     auto* context = extension_service_->GetBrowserContext();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     is_deprecated_app = extensions::IsExtensionUnsupportedDeprecatedApp(
         context, extension->id());
 #endif
