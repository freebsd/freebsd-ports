--- chrome/browser/chrome_content_browser_client.cc.orig	2019-03-15 06:37:01 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -334,7 +334,7 @@
 #include "chromeos/services/secure_channel/secure_channel_service.h"
 #include "components/user_manager/user_manager.h"
 #include "services/service_manager/public/mojom/interface_provider_spec.mojom.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/chrome_browser_main_linux.h"
 #elif defined(OS_ANDROID)
 #include "base/android/application_status_listener.h"
@@ -373,7 +373,7 @@
 #include "chrome/common/importer/profile_import.mojom.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/webshare/share_service_impl.h"
 #endif
 
@@ -387,7 +387,7 @@
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "chrome/browser/ui/views/chrome_browser_main_extra_parts_views_linux.h"
 #endif
 
@@ -1099,7 +1099,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
 #elif defined(OS_CHROMEOS)
   main_parts = new chromeos::ChromeBrowserMainPartsChromeos(
       parameters, std::move(service_manifest_data_pack_));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   main_parts = new ChromeBrowserMainPartsLinux(
       parameters, std::move(service_manifest_data_pack_));
 #elif defined(OS_ANDROID)
@@ -1119,7 +1119,7 @@ content::BrowserMainParts* ChromeContentBrowserClient:
   // Construct additional browser parts. Stages are called in the order in
   // which they are added.
 #if defined(TOOLKIT_VIEWS)
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViewsLinux());
 #else
   main_parts->AddParts(new ChromeBrowserMainExtraPartsViews());
@@ -1886,7 +1886,7 @@ void ChromeContentBrowserClient::AppendExtraCommandLin
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     std::string switch_value;
     std::unique_ptr<metrics::ClientInfo> client_info =
@@ -3335,7 +3335,7 @@ void ChromeContentBrowserClient::GetAdditionalFileSyst
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -4097,7 +4097,7 @@ void ChromeContentBrowserClient::InitWebContextInterfa
 #if defined(OS_ANDROID)
   frame_interfaces_parameterized_->AddInterface(base::Bind(
       &ForwardToJavaWebContentsRegistry<blink::mojom::ShareService>));
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   frame_interfaces_->AddInterface(base::Bind(&ShareServiceImpl::Create));
 #endif
 
@@ -4609,7 +4609,7 @@ std::unique_ptr<content::OverlayWindow>
 ChromeContentBrowserClient::CreateWindowForPictureInPicture(
     content::PictureInPictureWindowController* controller) {
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+	defined(OS_CHROMEOS) || defined(OS_BSD)
   // Note: content::OverlayWindow::Create() is defined by platform-specific
   // implementation in chrome/browser/ui/views. This layering hack, which goes
   // through //content and ContentBrowserClient, allows us to work around the
