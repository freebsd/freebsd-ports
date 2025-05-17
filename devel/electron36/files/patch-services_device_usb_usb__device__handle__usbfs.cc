--- services/device/usb/usb_device_handle_usbfs.cc.orig	2025-04-22 20:15:27 UTC
+++ services/device/usb/usb_device_handle_usbfs.cc
@@ -39,7 +39,7 @@
 #include "chromeos/dbus/permission_broker/permission_broker_client.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "services/device/public/cpp/device_features.h"
 #include "services/device/usb/usb_interface_detach_allowlist.h"
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
@@ -271,7 +271,7 @@ bool UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper::R
   return true;
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool UsbDeviceHandleUsbfs::BlockingTaskRunnerHelper::DetachInterface(
     int interface_number,
     const CombinedInterfaceInfo& interface_info) {
@@ -599,7 +599,7 @@ void UsbDeviceHandleUsbfs::ClaimInterface(int interfac
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     const mojom::UsbConfigurationInfo* config =
         device_->GetActiveConfiguration();
@@ -945,7 +945,7 @@ void UsbDeviceHandleUsbfs::ReleaseInterfaceComplete(in
     return;
   }
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAutomaticUsbDetach)) {
     helper_.AsyncCall(&BlockingTaskRunnerHelper::ReattachInterface)
         .WithArgs(interface_number)
