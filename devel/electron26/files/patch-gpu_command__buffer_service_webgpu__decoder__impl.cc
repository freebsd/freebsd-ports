--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2023-08-10 01:48:44 UTC
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1235,7 +1235,7 @@ void WebGPUDecoderImpl::RequestAdapterImpl(
 
   if (gr_context_type_ != GrContextType::kVulkan &&
       use_webgpu_adapter_ != WebGPUAdapterName::kOpenGLES) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     callback(WGPURequestAdapterStatus_Unavailable, nullptr,
              "WebGPU on Linux requires command-line flag "
              "--enable-features=Vulkan",
