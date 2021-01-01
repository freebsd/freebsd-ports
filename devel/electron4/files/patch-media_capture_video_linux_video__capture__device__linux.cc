--- media/capture/video/linux/video_capture_device_linux.cc.orig	2019-03-15 06:37:27 UTC
+++ media/capture/video/linux/video_capture_device_linux.cc
@@ -22,6 +22,7 @@
 
 namespace media {
 
+#if !defined(OS_FREEBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
@@ -35,6 +36,7 @@ std::list<uint32_t> VideoCaptureDeviceLinux::GetListOf
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD)
 
 VideoCaptureDeviceLinux::VideoCaptureDeviceLinux(
     scoped_refptr<V4L2CaptureDevice> v4l2,
@@ -53,6 +55,7 @@ VideoCaptureDeviceLinux::~VideoCaptureDeviceLinux() {
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
+#if !defined(OS_FREEBSD)
   DCHECK(!capture_impl_);
   if (v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -78,9 +81,11 @@ void VideoCaptureDeviceLinux::AllocateAndStart(
   for (const auto& request : photo_requests_queue_)
     v4l2_thread_.task_runner()->PostTask(FROM_HERE, request);
   photo_requests_queue_.clear();
+#endif // !defined(OS_FREEBSD)
 }
 
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
+#if !defined(OS_FREEBSD)
   if (!v4l2_thread_.IsRunning())
     return;  // Wrong state.
   v4l2_thread_.task_runner()->PostTask(
@@ -90,6 +95,7 @@ void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   v4l2_thread_.Stop();
 
   capture_impl_ = nullptr;
+#endif // !defined(OS_FREEBSD)
 }
 
 void VideoCaptureDeviceLinux::TakePhoto(TakePhotoCallback callback) {
@@ -132,11 +138,13 @@ void VideoCaptureDeviceLinux::SetPhotoOptions(
 }
 
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
+#if !defined(OS_BSD)
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.task_runner()->PostTask(
         FROM_HERE, base::Bind(&V4L2CaptureDelegate::SetRotation,
                               capture_impl_->GetWeakPtr(), rotation));
   }
+#endif
 }
 
 // static
