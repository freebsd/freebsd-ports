--- content/renderer/renderer_blink_platform_impl.h.orig	2025-02-02 01:39:08 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -257,7 +257,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
