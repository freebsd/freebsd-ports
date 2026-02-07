--- CMake/Modules/FindUsb.cmake.orig	2024-09-27 09:47:22 UTC
+++ CMake/Modules/FindUsb.cmake
@@ -27,7 +27,7 @@ libfind_pkg_detect (Usb usb-1.0
 endif ()
 libfind_pkg_detect (Usb usb-1.0
   FIND_PATH libusb.h PATH_SUFFIXES libusb-1.0
-  FIND_LIBRARY usb-1.0 ${_library_options}
+  FIND_LIBRARY usb-1.0 usb ${_library_options}
   )
 
 libfind_process (Usb)
