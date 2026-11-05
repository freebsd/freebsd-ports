--- CMake/Modules/FindUsb.cmake.orig	2026-06-18 16:22:52 UTC
+++ CMake/Modules/FindUsb.cmake
@@ -25,10 +25,17 @@ endif ()
     set (_library_options PATH_SUFFIXES MinGW32/dll MinGW32/static)
   endif ()
 endif ()
-libfind_pkg_detect (Usb usb-1.0
-  FIND_PATH libusb.h PATH_SUFFIXES include/libusb-1.0
-  FIND_LIBRARY usb-1.0 ${_library_options}
+if (BSD) 
+    libfind_pkg_detect (Usb usb
+    FIND_PATH libusb.h PATH_SUFFIXES include/libusb
+    FIND_LIBRARY usb ${_library_options}
   )
+else() 
+    libfind_pkg_detect (Usb usb-1.0
+    FIND_PATH libusb.h PATH_SUFFIXES include/libusb-1.0
+    FIND_LIBRARY usb-1.0 ${_library_options}
+  )
+endif()
 
 libfind_process (Usb)
 
