--- src/calibre/devices/usbms/device.py.orig	2016-03-11 03:07:28 UTC
+++ src/calibre/devices/usbms/device.py
@@ -699,7 +699,8 @@ class Device(DeviceConfig, DevicePlugin)
                         d.manufacturer == objif.GetProperty('usb.vendor') and \
                         d.product == objif.GetProperty('usb.product') and \
                         d.serial == objif.GetProperty('usb.serial'):
-                    dpaths = manager.FindDeviceStringMatch('storage.originating_device', path)
+                    midpath = manager.FindDeviceStringMatch('info.parent', path)
+                    dpaths = manager.FindDeviceStringMatch('storage.originating_device', path) + manager.FindDeviceStringMatch('storage.originating_device', midpath[0])
                     for dpath in dpaths:
                         # devif = dbus.Interface(bus.get_object('org.freedesktop.Hal', dpath), 'org.freedesktop.Hal.Device')
                         try:
