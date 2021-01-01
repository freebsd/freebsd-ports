--- content/renderer/renderer_blink_platform_impl.h.orig	2019-03-16 09:15:21 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -266,7 +266,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   std::unique_ptr<blink::WebThread> main_thread_;
   std::unique_ptr<service_manager::Connector> connector_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   class SandboxSupport;
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
