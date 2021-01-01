--- content/renderer/renderer_blink_platform_impl.cc.orig	2019-03-16 09:15:21 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -123,7 +123,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -201,7 +201,7 @@ gpu::ContextType ToGpuContextType(blink::Platform::Con
 
 //------------------------------------------------------------------------------
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -274,7 +274,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
     connector_ = service_manager::Connector::Create(&request);
   }
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
 #if defined(OS_MACOSX)
     sandbox_support_.reset(new RendererBlinkPlatformImpl::SandboxSupport());
@@ -302,7 +302,7 @@ RendererBlinkPlatformImpl::~RendererBlinkPlatformImpl(
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   // SandboxSupport contains a map of WebFallbackFont objects, which hold
   // WebStrings and WebVectors, which become invalidated when blink is shut
   // down. Hence, we need to clear that map now, just before blink::shutdown()
@@ -394,7 +394,7 @@ blink::BlameContext* RendererBlinkPlatformImpl::GetTop
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // These platforms do not require sandbox support.
   return NULL;
 #else
@@ -587,7 +587,7 @@ bool RendererBlinkPlatformImpl::SandboxSupport::LoadFo
   return content::LoadFont(src_font, out, font_id);
 }
 
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::GetFallbackFontForCharacter(
     blink::WebUChar32 character,
