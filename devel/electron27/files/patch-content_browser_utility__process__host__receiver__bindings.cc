--- content/browser/utility_process_host_receiver_bindings.cc.orig	2023-10-19 19:58:22 UTC
+++ content/browser/utility_process_host_receiver_bindings.cc
@@ -10,12 +10,12 @@
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/common/content_client.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "components/viz/host/gpu_client.h"
 #include "content/public/browser/gpu_client.h"
 #endif
@@ -24,13 +24,13 @@ namespace content {
 
 void UtilityProcessHost::BindHostReceiver(
     mojo::GenericPendingReceiver receiver) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (auto gpu_receiver = receiver.As<viz::mojom::Gpu>()) {
     gpu_client_ =
         content::CreateGpuClient(std::move(gpu_receiver), base::DoNothing());
