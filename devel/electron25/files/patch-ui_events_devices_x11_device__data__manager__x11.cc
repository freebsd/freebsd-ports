--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2023-02-01 18:43:51 UTC
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -875,6 +875,7 @@ void DeviceDataManagerX11::SetDisabledKeyboardAllowedK
 }
 
 void DeviceDataManagerX11::DisableDevice(x11::Input::DeviceId deviceid) {
+  NOTIMPLEMENTED();
   blocked_devices_.set(static_cast<uint32_t>(deviceid), true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<InputDevice> keyboards = GetKeyboardDevices();
