--- content/renderer/render_thread_impl.cc.orig	2023-10-25 09:13:43 UTC
+++ content/renderer/render_thread_impl.cc
@@ -204,6 +204,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -1054,7 +1056,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
                              kGpuStreamIdMedia, kGpuStreamPriorityMedia);
 
   const bool enable_video_decode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) &&
 #endif  // BUILDFLAG(IS_LINUX)
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
@@ -1063,7 +1065,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
        gpu::kGpuFeatureStatusEnabled);
 
   const bool enable_video_encode_accelerator =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoEncodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoEncode) &&
@@ -1835,7 +1837,7 @@ std::unique_ptr<CodecFactory> RenderThreadImpl::Create
     bool enable_video_encode_accelerator) {
   mojo::PendingRemote<media::mojom::VideoEncodeAcceleratorProvider>
       vea_provider;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(media::kUseOutOfProcessVideoEncoding)) {
     BindHostReceiver(vea_provider.InitWithNewPipeAndPassReceiver());
   } else {
