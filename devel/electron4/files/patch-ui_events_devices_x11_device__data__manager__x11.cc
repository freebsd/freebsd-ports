--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2019-03-15 06:38:27 UTC
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -829,6 +829,8 @@ void DeviceDataManagerX11::SetDisabledKeyboardAllowedK
 }
 
 void DeviceDataManagerX11::DisableDevice(int deviceid) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD)
   blocked_devices_.set(deviceid, true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<InputDevice> keyboards = GetKeyboardDevices();
@@ -840,6 +842,7 @@ void DeviceDataManagerX11::DisableDevice(int deviceid)
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(int deviceid) {
