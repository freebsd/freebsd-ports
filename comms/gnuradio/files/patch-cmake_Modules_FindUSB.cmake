--- cmake/Modules/FindUSB.cmake.orig	2012-04-09 10:38:58.000000000 -0500
+++ cmake/Modules/FindUSB.cmake	2014-03-02 20:19:39.000000000 -0500
@@ -1,20 +1,38 @@
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
+  message(status "--- LIBUSB_INCLUDE_DIR ${LIBUSB_INCLUDE_DIR}")
+
+  if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    message(status "--- Looking for FreeBSD usb")
+    find_library(LIBUSB_LIBRARIES NAMES usb
+      PATHS
+      ${LIBUSB_PKG_LIBRARY_DIRS}
+      /usr/lib
+    )
+
+  message(status "--- LIBUSB_LIBRARIES ${LIBUSB_LIBRARIES}")
 
-  find_library(LIBUSB_LIBRARIES NAMES usb-1.0
+    CHECK_LIBRARY_EXISTS(${LIBUSB_LIBRARIES} "libusb_get_string_descriptor"
+	"/usr/lib" HAVE_LIBUSB_GET_STRING_DESCRIPTOR)
+    if (HAVE_LIBUSB_GET_STRING_DESCRIPTOR)
+      add_definitions( -DHAVE_LIBUSB_GET_STRING_DESCRIPTOR=${HAVE_LIBUSB_GET_STRING_DESCRIPTOR})
+    endif()
+    message(status "--- HAVE_LIBUSB_GET_STRING_DESCRIPTOR ${HAVE_LIBUSB_STRING_DESCRIPTOR}")
+  endif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+
+  find_library(LIBUSB_LIBRARIES NAMES usb
     PATHS
     ${LIBUSB_PKG_LIBRARY_DIRS}
     /usr/lib
     /usr/local/lib
   )
-
 if(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARIES)
   set(LIBUSB_FOUND TRUE CACHE INTERNAL "libusb-1.0 found")
   message(STATUS "Found libusb-1.0: ${LIBUSB_INCLUDE_DIR}, ${LIBUSB_LIBRARIES}")
