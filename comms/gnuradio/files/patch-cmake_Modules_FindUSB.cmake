--- cmake/Modules/FindUSB.cmake.orig	2016-09-02 04:16:12 UTC
+++ cmake/Modules/FindUSB.cmake
@@ -1,20 +1,32 @@
 if(NOT LIBUSB_FOUND)
-  pkg_check_modules (LIBUSB_PKG libusb-1.0)
-  find_path(LIBUSB_INCLUDE_DIR NAMES libusb.h
-    PATHS
-    ${LIBUSB_PKG_INCLUDE_DIRS}
-    /usr/include/libusb-1.0
-    /usr/include
-    /usr/local/include
-  )
-
-  find_library(LIBUSB_LIBRARIES NAMES usb-1.0 usb
-    PATHS
-    ${LIBUSB_PKG_LIBRARY_DIRS}
-    /usr/lib
-    /usr/local/lib
-  )
+  if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    message(status "--- Looking for FreeBSD usb")
+    set (LIBUSB_INCLUDE_DIR ${LOCALBASE}/include)
+  find_library(LIBUSB_LIBRARIES NAMES usb
+      PATHS
+      ${LIBUSB_PKG_LIBRARY_DIRS}
+      /usr/lib
+    )
+  else()
+    message(status "--- LIBUSB_LIBRARIES ${LIBUSB_LIBRARIES}")
+    pkg_check_modules (LIBUSB_PKG libusb-1.0)
+    find_path(LIBUSB_INCLUDE_DIR NAMES libusb.h
+      PATHS
+      ${LIBUSB_PKG_INCLUDE_DIRS}
+      /usr/include/libusb-1.0
+      /usr/include
+      /usr/local/include
+    )
 
+    find_library(LIBUSB_LIBRARIES NAMES usb-1.0 usb
+      PATHS
+      ${LIBUSB_PKG_LIBRARY_DIRS}
+      /usr/lib
+      /usr/local/lib
+    )
+  endif()
+message( status "--- LIBUSB_INCLUDE_DIR ${LIBUSB_INCLUDE_DIR} LIBUSB_LIBRARIES ${LIBUSB_LIBRARIES}")
+  
 if(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARIES)
   set(LIBUSB_FOUND TRUE CACHE INTERNAL "libusb-1.0 found")
   message(STATUS "Found libusb-1.0: ${LIBUSB_INCLUDE_DIR}, ${LIBUSB_LIBRARIES}")
@@ -22,6 +34,19 @@ else(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRA
   set(LIBUSB_FOUND FALSE CACHE INTERNAL "libusb-1.0 found")
   message(STATUS "libusb-1.0 not found.")
 endif(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARIES)
+if(UNIX)
+  INCLUDE(CheckFunctionExists)
+endif()
+message(status "--- Checking for libusb_get_string_descriptor")
+set(CMAKE_REQUIRED_LIBRARIES ${LIBUSB_LIBRARIES})
+CHECK_FUNCTION_EXISTS(libusb_get_string_descriptor HAVE_LIBUSB_GET_STRING_DESCRIPTOR)
+
+if (HAVE_LIBUSB_GET_STRING_DESCRIPTOR)
+   add_definitions( -DHAVE_LIBUSB_GET_STRING_DESCRIPTOR)
+   message(status "--- Found libusb_get_string_descriptor")
+else()
+   message(status "--- libusb_get_string_descriptor Not Found")
+endif()
 
 mark_as_advanced(LIBUSB_INCLUDE_DIR LIBUSB_LIBRARIES)
 
