--- media/gpu/chromeos/video_decoder_pipeline.cc.orig	2023-09-05 21:58:02 UTC
+++ media/gpu/chromeos/video_decoder_pipeline.cc
@@ -986,14 +986,14 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_VAAPI)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_VAAPI)
   // Linux should always use a custom allocator (to allocate buffers using
   // libva) and a PlatformVideoFramePool.
   CHECK(allocator.has_value());
   CHECK(main_frame_pool_->AsPlatformVideoFramePool());
   main_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
       *allocator);
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
   // Linux w/ V4L2 should not use a custom allocator
   // Only tested with video_decode_accelerator_tests
   // TODO(wenst@) Test with full Chromium Browser
@@ -1124,7 +1124,7 @@ VideoDecoderPipeline::PickDecoderOutputFormat(
              << " VideoFrames";
     auxiliary_frame_pool_->set_parent_task_runner(decoder_task_runner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auxiliary_frame_pool_->AsPlatformVideoFramePool()->SetCustomFrameAllocator(
         *allocator);
 #endif
