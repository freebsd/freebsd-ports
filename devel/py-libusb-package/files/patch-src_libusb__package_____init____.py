--- src/libusb_package/__init__.py.orig	2023-06-11 19:21:48 UTC
+++ src/libusb_package/__init__.py
@@ -37,6 +37,7 @@ _LIBRARY_MAP_EXT = {
 _LIBRARY_MAP_EXT = {
         'Darwin': '.dylib',
         'Linux': '.so',
+        'FreeBSD': '.so',
         'Windows': '.dll',
     }
 _LIBRARY_EXT = _LIBRARY_MAP_EXT.get(platform.system(), ".so")
