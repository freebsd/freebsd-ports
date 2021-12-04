--- CMake/Modules/FindUsb.cmake	2021-11-30 23:55:50.616592000 -0500
+++ CMake/Modules/FindUsb.cmake	2021-11-30 23:56:00.350981000 -0500
@@ -27,7 +27,7 @@
 endif ()
 libfind_pkg_detect (Usb usb-1.0
   FIND_PATH libusb.h PATH_SUFFIXES libusb-1.0
-  FIND_LIBRARY usb-1.0 ${_library_options}
+  FIND_LIBRARY usb-1.0 usb ${_library_options}
   )
 
 libfind_process (Usb)
