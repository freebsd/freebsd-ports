--- chromecast/browser/cast_content_browser_client_receiver_bindings.cc.orig	2021-07-15 19:13:36 UTC
+++ chromecast/browser/cast_content_browser_client_receiver_bindings.cc
@@ -35,7 +35,7 @@
 #include "media/mojo/services/media_service.h"  // nogncheck
 #endif  // BUILDFLAG(ENABLE_CAST_RENDERER)
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
 #include "chromecast/browser/webview/js_channel_service.h"
 #include "chromecast/common/mojom/js_channel.mojom.h"
 #endif
@@ -205,7 +205,7 @@ void CastContentBrowserClient::RunServiceInstance(
 void CastContentBrowserClient::BindHostReceiverForRenderer(
     content::RenderProcessHost* render_process_host,
     mojo::GenericPendingReceiver receiver) {
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
   if (auto r = receiver.As<::chromecast::mojom::JsChannelBindingProvider>()) {
     JsChannelService::Create(render_process_host, std::move(r),
                              base::ThreadTaskRunnerHandle::Get());
