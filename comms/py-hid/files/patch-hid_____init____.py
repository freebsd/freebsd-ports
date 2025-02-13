--- hid/__init__.py.orig	2025-02-13 08:24:09 UTC
+++ hid/__init__.py
@@ -8,6 +8,7 @@ library_paths = (
 
 hidapi = None
 library_paths = (
+    'libhidapi.so',
     'libhidapi-hidraw.so',
     'libhidapi-hidraw.so.0',
     'libhidapi-libusb.so',
