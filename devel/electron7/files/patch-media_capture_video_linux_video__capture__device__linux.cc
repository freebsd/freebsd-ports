--- media/capture/video/linux/video_capture_device_linux.cc.orig	2019-12-12 12:39:49 UTC
+++ media/capture/video/linux/video_capture_device_linux.cc
@@ -37,6 +37,7 @@ int TranslatePowerLineFrequencyToV4L2(PowerLineFrequen
 
 }  // namespace
 
+#if !defined(OS_FREEBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
@@ -50,6 +51,7 @@ std::vector<uint32_t> VideoCaptureDeviceLinux::GetList
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD)
 
 VideoCaptureDeviceLinux::VideoCaptureDeviceLinux(
     scoped_refptr<V4L2CaptureDevice> v4l2,
@@ -71,6 +73,7 @@ void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+#if !defined(OS_FREEBSD)
   DCHECK(!capture_impl_);
   if (v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -98,10 +101,12 @@ void VideoCaptureDeviceLinux::AllocateAndStart(
   for (auto& request : photo_requests_queue_)
     v4l2_thread_.task_runner()->PostTask(FROM_HERE, std::move(request));
   photo_requests_queue_.clear();
+#endif // !defined(OS_FREEBSD)
 }
 
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+#if !defined(OS_FREEBSD)
   if (!v4l2_thread_.IsRunning())
     return;  // Wrong state.
   v4l2_thread_.task_runner()->PostTask(
@@ -111,6 +116,7 @@ void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   v4l2_thread_.Stop();
 
   capture_impl_ = nullptr;
+#endif // !defined(OS_FREEBSD)
 }
 
 void VideoCaptureDeviceLinux::TakePhoto(TakePhotoCallback callback) {
@@ -158,11 +164,13 @@ void VideoCaptureDeviceLinux::SetPhotoOptions(
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   rotation_ = rotation;
+#if !defined(OS_FREEBSD)
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.task_runner()->PostTask(
         FROM_HERE, base::BindOnce(&V4L2CaptureDelegate::SetRotation,
                                   capture_impl_->GetWeakPtr(), rotation));
   }
+#endif // !defined(OS_FREEBSD)
 }
 
 }  // namespace media
