--- content/renderer/renderer_blink_platform_impl.cc.orig	2024-04-28 08:50:04 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -115,7 +115,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
@@ -185,13 +185,13 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
       is_locked_to_site_(false),
       main_thread_scheduler_(main_thread_scheduler),
       next_frame_sink_id_(uint32_t{std::numeric_limits<int32_t>::max()} + 1) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   sk_sp<font_service::FontLoader> font_loader;
 #endif
 
   // RenderThread may not exist in some tests.
   if (RenderThreadImpl::current()) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -200,7 +200,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (sandboxEnabled()) {
 #if BUILDFLAG(IS_MAC)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -261,7 +261,7 @@ blink::WebSandboxSupport* RendererBlinkPlatformImpl::G
 #endif
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
