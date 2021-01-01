--- media/gpu/libyuv_image_processor.cc.orig	2019-09-10 11:14:08 UTC
+++ media/gpu/libyuv_image_processor.cc
@@ -91,7 +91,7 @@ std::unique_ptr<LibYUVImageProcessor> LibYUVImageProce
   // LibYUVImageProcessor supports only memory-based video frame for input.
   VideoFrame::StorageType input_storage_type = VideoFrame::STORAGE_UNKNOWN;
   for (auto input_type : input_config.preferred_storage_types) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     if (input_type == VideoFrame::STORAGE_DMABUFS) {
       video_frame_mapper = VideoFrameMapperFactory::CreateMapper(
           input_config.layout.format(), true);
@@ -100,7 +100,7 @@ std::unique_ptr<LibYUVImageProcessor> LibYUVImageProce
         break;
       }
     }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
     if (VideoFrame::IsStorageTypeMappable(input_type)) {
       input_storage_type = input_type;
@@ -203,7 +203,7 @@ void LibYUVImageProcessor::ProcessTask(scoped_refptr<V
                                        FrameReadyCB cb) {
   DCHECK(process_thread_.task_runner()->BelongsToCurrentThread());
   DVLOGF(4);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (input_frame->storage_type() == VideoFrame::STORAGE_DMABUFS) {
     DCHECK_NE(video_frame_mapper_.get(), nullptr);
     input_frame = video_frame_mapper_->Map(std::move(input_frame));
@@ -213,7 +213,7 @@ void LibYUVImageProcessor::ProcessTask(scoped_refptr<V
       return;
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   int res = DoConversion(input_frame.get(), output_frame.get());
   if (res != 0) {
