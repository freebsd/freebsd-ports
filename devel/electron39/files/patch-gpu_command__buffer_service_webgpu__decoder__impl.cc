--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2026-04-19 02:47:31 UTC
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1750,7 +1750,7 @@ wgpu::Adapter WebGPUDecoderImpl::CreatePreferredAdapte
       backend_types = {wgpu::BackendType::D3D12};
 #elif BUILDFLAG(IS_APPLE)
       backend_types = {wgpu::BackendType::Metal};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (shared_context_state_->GrContextIsVulkan() ||
           shared_context_state_->IsGraphiteDawnVulkan()) {
         backend_types = {wgpu::BackendType::Vulkan};
@@ -1995,7 +1995,7 @@ WebGPUDecoderImpl::AssociateMailboxDawn(
   }
 
 #if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (usage & wgpu::TextureUsage::StorageBinding) {
     LOG(ERROR) << "AssociateMailbox: wgpu::TextureUsage::StorageBinding is NOT "
                   "supported yet on this platform.";
