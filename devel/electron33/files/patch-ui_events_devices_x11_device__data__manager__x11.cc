--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2024-10-16 21:32:39 UTC
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -849,6 +849,7 @@ void DeviceDataManagerX11::DisableDevice(x11::Input::D
 }
 
 void DeviceDataManagerX11::DisableDevice(x11::Input::DeviceId deviceid) {
+  NOTIMPLEMENTED();
   blocked_devices_.set(static_cast<uint32_t>(deviceid), true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<KeyboardDevice> keyboards = GetKeyboardDevices();
