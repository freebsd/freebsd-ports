https://lists.freebsd.org/pipermail/freebsd-usb/2015-January/013586.html

--- usb1/__init__.py.orig	2021-09-24 22:30:54 UTC
+++ usb1/__init__.py
@@ -1885,8 +1885,10 @@ class USBDevice:
         Get the port number of each hub toward device.
         """
         port_list = (c_uint8 * PATH_MAX_DEPTH)()
+        temp_handle = self.open()
         result = libusb1.libusb_get_port_numbers(
             self.device_p, port_list, len(port_list))
+        temp_handle.close()
         mayRaiseUSBError(result)
         return list(port_list[:result])
 
