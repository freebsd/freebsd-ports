--- hid/__init__.py.orig	2024-04-11 03:39:41 UTC
+++ hid/__init__.py
@@ -7,6 +7,7 @@ library_paths = (
 
 hidapi = None
 library_paths = (
+    'libhidapi.so',
     'libhidapi-hidraw.so',
     'libhidapi-hidraw.so.0',
     'libhidapi-libusb.so',
