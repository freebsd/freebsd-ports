--- src/calibre/devices/libusb.py.orig	2009-10-10 06:15:00.000000000 +0400
+++ src/calibre/devices/libusb.py	2009-10-11 23:19:54.000000000 +0400
@@ -8,10 +8,10 @@
                    c_ubyte, c_ushort, c_int, c_char, c_void_p, c_byte, c_uint
 from errno import EBUSY, ENOMEM
 
-from calibre import iswindows, isosx, load_library
+from calibre import iswindows, isosx, isfreebsd, load_library
 
 _libusb_name = 'libusb'
-PATH_MAX = 511 if iswindows else 1024 if isosx else 4096
+PATH_MAX = 511 if iswindows else 1024 if isosx else 1024 if isfreebsd else 4096
 if iswindows:
     class Structure(_Structure):
         _pack_ = 1
