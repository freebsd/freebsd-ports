https://lists.freebsd.org/pipermail/freebsd-usb/2015-January/013586.html

--- usb1/__init__.py.orig	2021-07-02 12:59:01 UTC
+++ usb1/__init__.py
@@ -1864,8 +1864,10 @@ class USBDevice(object):
         Get the port number of each hub toward device.
         """
         port_list = (c_uint8 * PATH_MAX_DEPTH)()
+        temp_handle = self.open()
         result = libusb1.libusb_get_port_numbers(
             self.device_p, port_list, len(port_list))
+        temp_handle.close()
         mayRaiseUSBError(result)
         return list(port_list[:result])
 
