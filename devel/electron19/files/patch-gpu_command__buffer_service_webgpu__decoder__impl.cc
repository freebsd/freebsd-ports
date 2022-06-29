--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2022-05-25 04:01:02 UTC
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1547,7 +1547,7 @@ error::Error WebGPUDecoderImpl::HandleRequestAdapter(
 
   if (gr_context_type_ != GrContextType::kVulkan &&
       use_webgpu_adapter_ != WebGPUAdapterName::kCompat) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SendAdapterProperties(request_adapter_serial, -1, nullptr,
                           "WebGPU on Linux requires command-line flag "
                           "--enable-features=Vulkan,UseSkiaRenderer");
