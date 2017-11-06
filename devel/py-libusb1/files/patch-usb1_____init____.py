https://lists.freebsd.org/pipermail/freebsd-usb/2015-January/013586.html

--- usb1/__init__.py.orig	2016-11-23 13:07:52 UTC
+++ usb1/__init__.py
@@ -1830,15 +1830,20 @@ class USBDevice(object):
         """
         Get device's port number.
         """
-        return libusb1.libusb_get_port_number(self.device_p)
+        try:
+            return libusb1.libusb_get_port_number(self.device_p)
+        except AttributeError:
+            return 0
 
     def getPortNumberList(self):
         """
         Get the port number of each hub toward device.
         """
         port_list = (c_uint8 * PATH_MAX_DEPTH)()
+        temp_handle = self.open()
         result = libusb1.libusb_get_port_numbers(
             self.device_p, port_list, len(port_list))
+        temp_handle.close()
         mayRaiseUSBError(result)
         return list(port_list[:result])
 
