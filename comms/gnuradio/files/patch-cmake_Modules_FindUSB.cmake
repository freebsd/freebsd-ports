--- cmake/Modules/FindUSB.cmake.orig	2016-09-02 04:16:12 UTC
+++ cmake/Modules/FindUSB.cmake
@@ -22,6 +22,19 @@ else(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRA
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
 
