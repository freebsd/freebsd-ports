--- chrome/browser/ui/webui/app_home/app_home_page_handler.cc.orig	2024-02-21 00:20:37 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.cc
@@ -386,7 +386,7 @@ app_home::mojom::AppInfoPtr AppHomePageHandler::Create
 
   bool deprecated_app = false;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   auto* context = extension_system_->extension_service()->GetBrowserContext();
   deprecated_app =
       extensions::IsExtensionUnsupportedDeprecatedApp(context, extension->id());
@@ -450,7 +450,7 @@ void AppHomePageHandler::FillExtensionInfoList(
     }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     auto* context = extension_system_->extension_service()->GetBrowserContext();
     const bool is_deprecated_app =
         extensions::IsExtensionUnsupportedDeprecatedApp(context,
