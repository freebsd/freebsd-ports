--- media/capture/video/linux/v4l2_capture_delegate.h.orig	2023-10-19 19:58:26 UTC
+++ media/capture/video/linux/v4l2_capture_delegate.h
@@ -35,7 +35,7 @@ class Location;
 
 namespace media {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class V4L2CaptureDelegateGpuHelper;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -86,7 +86,7 @@ class CAPTURE_EXPORT V4L2CaptureDelegate final {
   static bool IsBlockedControl(int control_id);
   static bool IsControllableControl(
       int control_id,
-      const base::RepeatingCallback<int(int, void*)>& do_ioctl);
+      const base::RepeatingCallback<int(unsigned int, void*)>& do_ioctl);
 
   void SetGPUEnvironmentForTesting(
       std::unique_ptr<gpu::GpuMemoryBufferSupport> gmb_support);
@@ -100,10 +100,10 @@ class CAPTURE_EXPORT V4L2CaptureDelegate final {
   // device file descriptor or (re)starting streaming, can fail but works after
   // retrying (https://crbug.com/670262). Returns false if the |request| ioctl
   // fails too many times.
-  bool RunIoctl(int request, void* argp);
+  bool RunIoctl(unsigned int request, void* argp);
 
   // Simple wrapper to do HANDLE_EINTR(v4l2_->ioctl(device_fd_.get(), ...)).
-  int DoIoctl(int request, void* argp);
+  int DoIoctl(unsigned int request, void* argp);
 
   // Check whether the control is controllable (and not changed automatically).
   bool IsControllableControl(int control_id);
@@ -133,7 +133,7 @@ class CAPTURE_EXPORT V4L2CaptureDelegate final {
                      const base::Location& from_here,
                      const std::string& reason);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Systems which describe a "color space" usually map that to one or more of
   // {primary, matrix, transfer, range}. BuildColorSpaceFromv4l2() will use the
   // matched value as first priority. Otherwise, if there is no best matching
@@ -167,7 +167,7 @@ class CAPTURE_EXPORT V4L2CaptureDelegate final {
   // Clockwise rotation in degrees. This value should be 0, 90, 180, or 270.
   int rotation_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Support GPU memory buffer.
   bool use_gpu_buffer_;
   std::unique_ptr<V4L2CaptureDelegateGpuHelper> v4l2_gpu_helper_;
