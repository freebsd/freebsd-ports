https://lists.freebsd.org/pipermail/freebsd-usb/2015-January/013586.html

--- usb1/__init__.py.orig	2022-02-06 04:49:47 UTC
+++ usb1/__init__.py
@@ -1884,8 +1884,10 @@ class USBDevice:
         Get the port number of each hub toward device.
         """
         port_list = (c_uint8 * PATH_MAX_DEPTH)()
+        temp_handle = self.open()
         result = libusb1.libusb_get_port_numbers(
             self.device_p, port_list, len(port_list))
+        temp_handle.close()
         mayRaiseUSBError(result)
         return list(port_list[:result])
 
