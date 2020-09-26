We cannot really distinguish between USB and non-USB here,
as port[2] is 'n/a' on FreeBSD.

--- plugins/USBPrinting/USBPrinterOutputDeviceManager.py.orig	2020-07-23 19:29:25 UTC
+++ plugins/USBPrinting/USBPrinterOutputDeviceManager.py
@@ -123,8 +123,6 @@
                 port = (port.device, port.description, port.hwid)
             if not port[2]:  # HWID may be None if the device is not USB or the system doesn't report the type.
                 continue
-            if only_list_usb and not port[2].startswith("USB"):
-                continue
 
             # To prevent cura from messing with serial ports of other devices,
             # filter by regular expressions passed in as environment variables.
