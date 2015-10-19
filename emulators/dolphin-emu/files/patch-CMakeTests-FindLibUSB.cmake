Adapt libusb name for FreeBSD

--- CMakeTests/FindLibUSB.cmake.orig	2015-10-09 20:30:03.218968702 +0000
+++ CMakeTests/FindLibUSB.cmake	2015-10-09 20:36:02.787944507 +0000
@@ -23,7 +23,13 @@
        /usr/local/include
     )
 
-    find_library(LIBUSB_LIBRARIES NAMES usb-1.0
+    if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
+        set(LIBUSB_LIBRARY "usb")
+    else()
+        set(LIBUSB_LIBRARY "usb-1.0")
+    endif()
+
+    find_library(LIBUSB_LIBRARIES NAMES ${LIBUSB_LIBRARY}
        PATHS
        ${LIBUSB_PKG_LIBRARY_DIRS}
        /usr/lib
