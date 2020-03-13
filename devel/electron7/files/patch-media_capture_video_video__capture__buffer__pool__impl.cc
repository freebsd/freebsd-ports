--- media/capture/video/video_capture_buffer_pool_impl.cc.orig	2019-12-12 12:39:49 UTC
+++ media/capture/video/video_capture_buffer_pool_impl.cc
@@ -57,7 +57,7 @@ VideoCaptureBufferPoolImpl::CreateSharedMemoryViaRawFi
     int buffer_id) {
 // This requires platforms where base::SharedMemoryHandle is backed by a
 // file descriptor.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::AutoLock lock(lock_);
 
   VideoCaptureBufferTracker* tracker = GetTracker(buffer_id);
