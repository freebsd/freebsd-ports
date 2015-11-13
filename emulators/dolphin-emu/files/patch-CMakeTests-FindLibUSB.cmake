Adapt libusb name for FreeBSD

--- CMakeTests/FindLibUSB.cmake.orig	2015-07-31 10:04:05.000000000 +0000
+++ CMakeTests/FindLibUSB.cmake	2015-10-25 12:51:34.455592341 +0000
@@ -23,7 +23,7 @@
        /usr/local/include
     )
 
-    find_library(LIBUSB_LIBRARIES NAMES usb-1.0
+    find_library(LIBUSB_LIBRARIES NAMES usb-1.0 usb
        PATHS
        ${LIBUSB_PKG_LIBRARY_DIRS}
        /usr/lib
