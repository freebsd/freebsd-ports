--- services/device/usb/usb_device_handle_usbfs.h.orig	2025-04-22 20:15:27 UTC
+++ services/device/usb/usb_device_handle_usbfs.h
@@ -19,7 +19,7 @@
 #include "base/threading/sequence_bound.h"
 #include "services/device/usb/usb_device_handle.h"
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/containers/flat_set.h"
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
@@ -215,7 +215,7 @@ class UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper {
   bool ClearHalt(uint8_t endpoint_address);
   void DiscardUrb(Transfer* transfer);
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Detach the interface from a kernel driver before ClaimInterface
   virtual bool DetachInterface(int interface_number,
                                const CombinedInterfaceInfo& interfaceInfo);
@@ -228,7 +228,7 @@ class UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper {
   // Called when |fd_| is writable without blocking.
   void OnFileCanWriteWithoutBlocking();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Called from |DetachInterface|.
   std::string GetKernelDriver(int interface_number) const;
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
@@ -240,7 +240,7 @@ class UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper {
   std::unique_ptr<base::FileDescriptorWatcher::Controller> watch_controller_;
   SEQUENCE_CHECKER(sequence_checker_);
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // All interfaces that have been detached from kernel drivers
   base::flat_set<int> detached_interfaces_;
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
