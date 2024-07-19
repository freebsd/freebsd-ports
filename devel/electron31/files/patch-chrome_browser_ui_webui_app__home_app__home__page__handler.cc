--- chrome/browser/ui/webui/app_home/app_home_page_handler.cc.orig	2024-06-18 21:43:25 UTC
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.cc
@@ -376,7 +376,7 @@ app_home::mojom::AppInfoPtr AppHomePageHandler::Create
   app_info->start_url = start_url;
 
   bool deprecated_app = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* context = extension_system_->extension_service()->GetBrowserContext();
   deprecated_app =
       extensions::IsExtensionUnsupportedDeprecatedApp(context, extension->id());
@@ -439,7 +439,7 @@ void AppHomePageHandler::FillExtensionInfoList(
       continue;
     }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto* context = extension_system_->extension_service()->GetBrowserContext();
     const bool is_deprecated_app =
         extensions::IsExtensionUnsupportedDeprecatedApp(context,
