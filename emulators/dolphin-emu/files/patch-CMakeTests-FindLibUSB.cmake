--- CMakeTests/FindLibUSB.cmake.orig	2013-09-17 08:41:32.000000000 +0200
+++ CMakeTests/FindLibUSB.cmake	2013-09-17 08:41:41.000000000 +0200
@@ -23,7 +23,7 @@
        /usr/local/include
     )
 
-    find_library(LIBUSB_LIBRARIES NAMES usb-1.0
+    find_library(LIBUSB_LIBRARIES NAMES usb
        PATHS
        ${LIBUSB_PKG_LIBRARY_DIRS}
        /usr/lib
