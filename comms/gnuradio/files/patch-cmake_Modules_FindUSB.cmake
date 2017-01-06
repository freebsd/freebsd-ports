--- cmake/Modules/FindUSB.cmake.orig	2015-04-13 14:32:43 UTC
+++ cmake/Modules/FindUSB.cmake
@@ -23,6 +33,17 @@ else(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRA
   message(STATUS "libusb-1.0 not found.")
 endif(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARIES)
 
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
+
 mark_as_advanced(LIBUSB_INCLUDE_DIR LIBUSB_LIBRARIES)
 
 endif(NOT LIBUSB_FOUND)
