--- cmake/Modules/FindUSB.cmake.orig	2012-09-04 19:43:06.000000000 -0500
+++ cmake/Modules/FindUSB.cmake	2012-09-27 14:10:21.000000000 -0500
@@ -1,20 +1,34 @@
 if(NOT LIBUSB_FOUND)
-  pkg_check_modules (LIBUSB_PKG libusb-1.0)
-  find_path(LIBUSB_INCLUDE_DIR NAMES libusb.h
+    pkg_check_modules (LIBUSB_PKG libusb-1.0)
+
+    find_path(LIBUSB_INCLUDE_DIR NAMES libusb.h
     PATHS
     ${LIBUSB_PKG_INCLUDE_DIRS}
     /usr/include/libusb-1.0
     /usr/include
-    /usr/local/include
   )
 
-  find_library(LIBUSB_LIBRARIES NAMES usb-1.0
+  if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    message(status " Looking for FreeBSD usb")
+    find_library(LIBUSB_LIBRARIES NAMES usb-1.0
+    PATHS
+    ${LIBUSB_PKG_LIBRARY_DIRS}
+    /usr/lib
+  )
+  elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    find_library(LIBUSB_LIBRARIES NAMES usb-1.0
     PATHS
     ${LIBUSB_PKG_LIBRARY_DIRS}
     /usr/lib
-    /usr/local/lib
   )
+  endif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
 
+  find_library(LIBUSB_LIBRARIES NAMES usb
+    PATHS
+    ${LIBUSB_PKG_LIBRARY_DIRS}
+    /usr/lib
+    /usr/local/lib
+  )
 if(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARIES)
   set(LIBUSB_FOUND TRUE CACHE INTERNAL "libusb-1.0 found")
   message(STATUS "Found libusb-1.0: ${LIBUSB_INCLUDE_DIR}, ${LIBUSB_LIBRARIES}")
