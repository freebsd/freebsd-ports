--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2022-05-19 05:17:44 UTC
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -646,7 +646,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
@@ -668,7 +668,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
 #error "Unsupported platform"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // viable_candidate should always be set unless using L1 protected content,
   // which isn't an option on linux or lacros.
   CHECK(viable_candidate);
