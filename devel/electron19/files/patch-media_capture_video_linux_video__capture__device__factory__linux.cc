--- media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2022-05-11 07:16:53 UTC
+++ media/capture/video/linux/video_capture_device_factory_linux.cc
@@ -72,6 +72,9 @@ class DevVideoFilePathsDeviceProvider
     : public VideoCaptureDeviceFactoryLinux::DeviceProvider {
  public:
   void GetDeviceIds(std::vector<std::string>* target_container) override {
+#if defined(OS_OPENBSD)
+    target_container->emplace_back("/dev/video");
+#else
     const base::FilePath path("/dev/");
     base::FileEnumerator enumerator(path, false, base::FileEnumerator::FILES,
                                     "video*");
@@ -79,9 +82,13 @@ class DevVideoFilePathsDeviceProvider
       const base::FileEnumerator::FileInfo info = enumerator.GetInfo();
       target_container->emplace_back(path.value() + info.GetName().value());
     }
+#endif
   }
 
   std::string GetDeviceModelId(const std::string& device_id) override {
+#if defined(OS_OPENBSD)
+    return std::string();
+#endif
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     std::string usb_id;
     const std::string vid_path =
@@ -99,6 +106,9 @@ class DevVideoFilePathsDeviceProvider
   }
 
   std::string GetDeviceDisplayName(const std::string& device_id) override {
+#if defined(OS_OPENBSD)
+    return std::string();
+#endif
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     const std::string interface_path =
         base::StringPrintf(kInterfacePathTemplate, file_name.c_str());
@@ -213,7 +223,7 @@ void VideoCaptureDeviceFactoryLinux::GetDevicesInfo(
   std::move(callback).Run(std::move(devices_info));
 }
 
-int VideoCaptureDeviceFactoryLinux::DoIoctl(int fd, int request, void* argp) {
+int VideoCaptureDeviceFactoryLinux::DoIoctl(int fd, unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(fd, request, argp));
 }
 
