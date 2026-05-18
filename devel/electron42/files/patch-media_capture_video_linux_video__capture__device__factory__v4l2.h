--- media/capture/video/linux/video_capture_device_factory_v4l2.h.orig	2026-04-28 21:06:17 UTC
+++ media/capture/video/linux/video_capture_device_factory_v4l2.h
@@ -52,7 +52,7 @@ class CAPTURE_EXPORT VideoCaptureDeviceFactoryV4L2
 
  private:
   // Simple wrapper to do HANDLE_EINTR(v4l2_->ioctl(fd, ...)).
-  int DoIoctl(int fd, int request, void* argp);
+  int DoIoctl(int fd, unsigned int request, void* argp);
 
   VideoCaptureControlSupport GetControlSupport(int fd);
   bool GetControlSupport(int fd, int control_id);
