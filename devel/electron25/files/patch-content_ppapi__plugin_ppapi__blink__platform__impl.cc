--- content/ppapi_plugin/ppapi_blink_platform_impl.cc.orig	2023-05-25 00:41:55 UTC
+++ content/ppapi_plugin/ppapi_blink_platform_impl.cc
@@ -20,7 +20,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "mojo/public/cpp/bindings/pending_remote.h"
 #endif
@@ -35,7 +35,7 @@ typedef struct CGFont* CGFontRef;
 namespace content {
 
 PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   ChildThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -54,7 +54,7 @@ PpapiBlinkPlatformImpl::~PpapiBlinkPlatformImpl() {
 void PpapiBlinkPlatformImpl::Shutdown() {}
 
 blink::WebSandboxSupport* PpapiBlinkPlatformImpl::GetSandboxSupport() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
