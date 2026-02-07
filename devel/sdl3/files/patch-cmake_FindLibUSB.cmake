--- cmake/FindLibUSB.cmake.orig	2025-03-04 22:37:06 UTC
+++ cmake/FindLibUSB.cmake
@@ -10,7 +10,7 @@ find_library(LibUSB_LIBRARY
 endif()
 
 find_library(LibUSB_LIBRARY
-  NAMES usb-1.0 libusb-1.0
+  NAMES usb-1.0 libusb-1.0 usb
   HINTS ${PC_LibUSB_LIBRARY_DIRS}
 )
 
