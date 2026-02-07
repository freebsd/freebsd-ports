--- media/capture/video/linux/video_capture_device_factory_v4l2.cc.orig	2025-08-26 20:49:50 UTC
+++ media/capture/video/linux/video_capture_device_factory_v4l2.cc
@@ -44,6 +44,7 @@ bool CompareCaptureDevices(const VideoCaptureDeviceInf
   return a.descriptor < b.descriptor;
 }
 
+#if !BUILDFLAG(IS_OPENBSD)
 // USB VID and PID are both 4 bytes long.
 const size_t kVidPidSize = 4;
 const size_t kMaxInterfaceNameSize = 256;
@@ -76,11 +77,24 @@ std::string ExtractFileNameFromDeviceId(const std::str
   DCHECK(base::StartsWith(device_id, kDevDir, base::CompareCase::SENSITIVE));
   return device_id.substr(strlen(kDevDir), device_id.length());
 }
+#endif
 
 class DevVideoFilePathsDeviceProvider
     : public VideoCaptureDeviceFactoryV4L2::DeviceProvider {
  public:
   void GetDeviceIds(std::vector<std::string>* target_container) override {
+#if BUILDFLAG(IS_OPENBSD)
+    char device[12];
+    int fd;
+    /* unveil(2) limits access to /dev/, try /dev/video[0-7] */
+    for (int n = 0; n < 8; n++) {
+      snprintf(device, sizeof(device), "/dev/video%d", n);
+      if ((fd = open(device, O_RDONLY)) != -1) {
+        close(fd);
+        target_container->emplace_back(device);
+      }
+    }
+#else
     const base::FilePath path("/dev/");
     base::FileEnumerator enumerator(path, false, base::FileEnumerator::FILES,
                                     "video*");
@@ -88,9 +102,13 @@ class DevVideoFilePathsDeviceProvider
       const base::FileEnumerator::FileInfo info = enumerator.GetInfo();
       target_container->emplace_back(path.value() + info.GetName().value());
     }
+#endif
   }
 
   std::string GetDeviceModelId(const std::string& device_id) override {
+#if BUILDFLAG(IS_OPENBSD)
+    return std::string();
+#else
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     std::string usb_id;
     const std::string vid_path =
@@ -107,9 +125,13 @@ class DevVideoFilePathsDeviceProvider
     }
 
     return usb_id;
+#endif
   }
 
   std::string GetDeviceDisplayName(const std::string& device_id) override {
+#if BUILDFLAG(IS_OPENBSD)
+    return std::string();
+#else
     const std::string file_name = ExtractFileNameFromDeviceId(device_id);
     const std::string interface_path =
         base::StringPrintf(kInterfacePathTemplate, file_name.c_str());
@@ -120,6 +142,7 @@ class DevVideoFilePathsDeviceProvider
       return std::string();
     }
     return display_name;
+#endif
   }
 };
 
@@ -225,7 +248,7 @@ void VideoCaptureDeviceFactoryV4L2::GetDevicesInfo(
   std::move(callback).Run(std::move(devices_info));
 }
 
-int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, int request, void* argp) {
+int VideoCaptureDeviceFactoryV4L2::DoIoctl(int fd, unsigned int request, void* argp) {
   return HANDLE_EINTR(v4l2_->ioctl(fd, request, argp));
 }
 
