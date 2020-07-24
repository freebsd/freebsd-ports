We cannot really distinguish between USB and non-USB here,
as port[2] is 'n/a' on FreeBSD.

--- plugins/USBPrinting/USBPrinterOutputDeviceManager.py.orig	2020-07-23 19:29:25 UTC
+++ plugins/USBPrinting/USBPrinterOutputDeviceManager.py
@@ -112,8 +112,6 @@ class USBPrinterOutputDeviceManager(QObject, OutputDev
         for port in serial.tools.list_ports.comports():
             if not isinstance(port, tuple):
                 port = (port.device, port.description, port.hwid)
-            if only_list_usb and not port[2].startswith("USB"):
-                continue
 
             # To prevent cura from messing with serial ports of other devices,
             # filter by regular expressions passed in as environment variables.
