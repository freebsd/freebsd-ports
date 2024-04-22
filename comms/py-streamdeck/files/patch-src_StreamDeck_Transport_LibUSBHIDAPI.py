--- src/StreamDeck/Transport/LibUSBHIDAPI.py.orig	2024-04-08 21:05:19 UTC
+++ src/StreamDeck/Transport/LibUSBHIDAPI.py
@@ -154,6 +154,7 @@ class LibUSBHIDAPI(Transport):
                 "Windows": ["hidapi.dll", "libhidapi-0.dll", "./hidapi.dll"],
                 "Linux": ["libhidapi-libusb.so", "libhidapi-libusb.so.0"],
                 "Darwin": ["libhidapi.dylib"],
+                "FreeBSD": ["libhidapi.so"],
             }
 
             self.platform_name = platform.system()
