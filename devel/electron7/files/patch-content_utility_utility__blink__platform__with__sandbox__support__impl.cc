--- content/utility/utility_blink_platform_with_sandbox_support_impl.cc.orig	2019-12-12 12:39:43 UTC
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.cc
@@ -9,7 +9,7 @@
 
 #if defined(OS_MACOSX)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -18,7 +18,7 @@ namespace content {
 UtilityBlinkPlatformWithSandboxSupportImpl::
     UtilityBlinkPlatformWithSandboxSupportImpl(
         service_manager::Connector* connector) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   UtilityThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -35,7 +35,7 @@ UtilityBlinkPlatformWithSandboxSupportImpl::
 
 blink::WebSandboxSupport*
 UtilityBlinkPlatformWithSandboxSupportImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
