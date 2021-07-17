--- cmake/modules/FindLibUSB.cmake.orig	2021-06-28 20:04:59 UTC
+++ cmake/modules/FindLibUSB.cmake
@@ -57,7 +57,11 @@ find_path(LibUSB_INCLUDE_DIR
 mark_as_advanced(LibUSB_INCLUDE_DIR)
 
 find_library(LibUSB_LIBRARY
+if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
+  NAMES usb
+else
   NAMES usb-1.0
+endif()
   PATHS ${PC_LibUSB_LIBRARY_DIRS}
   DOC "LibUSB library"
 )
