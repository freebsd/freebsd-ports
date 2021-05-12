--- media/capture/video/fake_video_capture_device_factory.cc.orig	2021-01-07 00:36:36 UTC
+++ media/capture/video/fake_video_capture_device_factory.cc
@@ -208,7 +208,7 @@ void FakeVideoCaptureDeviceFactory::GetDevicesInfo(
   int entry_index = 0;
   for (const auto& entry : devices_config_) {
     VideoCaptureApi api =
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE;
 #elif defined(OS_MAC)
         VideoCaptureApi::MACOSX_AVFOUNDATION;
