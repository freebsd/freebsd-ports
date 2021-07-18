--- media/capture/video/file_video_capture_device_factory.cc.orig	2021-01-07 00:36:36 UTC
+++ media/capture/video/file_video_capture_device_factory.cc
@@ -52,7 +52,7 @@ void FileVideoCaptureDeviceFactory::GetDevicesInfo(
       VideoCaptureApi::WIN_DIRECT_SHOW;
 #elif defined(OS_MAC)
       VideoCaptureApi::MACOSX_AVFOUNDATION;
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE;
 #else
       VideoCaptureApi::UNKNOWN;
