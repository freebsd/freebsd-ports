--- content/renderer/renderer_blink_platform_impl.h.orig	2026-10-30 11:54:04 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -290,7 +290,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
                                const gpu::GPUInfo& gpu_info) const;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
