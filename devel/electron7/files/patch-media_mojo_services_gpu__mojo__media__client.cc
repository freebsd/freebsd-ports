--- media/mojo/services/gpu_mojo_media_client.cc.orig	2019-12-12 12:39:50 UTC
+++ media/mojo/services/gpu_mojo_media_client.cc
@@ -65,7 +65,7 @@ namespace media {
 namespace {
 
 #if defined(OS_ANDROID) || defined(OS_CHROMEOS) || defined(OS_MACOSX) || \
-    defined(OS_WIN) || defined(OS_LINUX)
+    defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 gpu::CommandBufferStub* GetCommandBufferStub(
     scoped_refptr<base::SingleThreadTaskRunner> gpu_task_runner,
     base::WeakPtr<MediaGpuChannelManager> media_gpu_channel_manager,
@@ -245,7 +245,7 @@ std::unique_ptr<VideoDecoder> GpuMojoMediaClient::Crea
                                 command_buffer_id->route_id));
       }
 
-#elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
       video_decoder = VdaVideoDecoder::Create(
           task_runner, gpu_task_runner_, media_log->Clone(), target_color_space,
           gpu_preferences_, gpu_workarounds_,
