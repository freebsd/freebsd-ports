--- src/cmake/Modules/FindRtlSdr.cmake.orig	2026-05-23 14:59:55 UTC
+++ src/cmake/Modules/FindRtlSdr.cmake
@@ -7,18 +7,24 @@
 #  RTLSDR_DEFINITIONS - Compiler switches required for using rtl-sdr
 #
 
+string(COMPARE EQUAL "FreeBSD" ${BSD} FreeBSD)
+
+if (${FreeBSD})
+    set(LIBUSB_NAME "usb")
+endif( FreeBSD)
+
 if (RTLSDR_LIBRARIES AND RTLSDR_INCLUDE_DIRS)
   # In cache already
   set(RTLSDR_FOUND TRUE)
 else (RTLSDR_LIBRARIES AND RTLSDR_INCLUDE_DIRS)
-  find_package(PkgConfig)
-  if(CMAKE_VERSION VERSION_LESS 2.8.2)
-    pkg_check_modules(PC_LIBUSB libusb-1.0)
-    pkg_check_modules(PC_RTLSDR librtlsdr)
-  else()
-    pkg_check_modules(PC_LIBUSB QUIET libusb-1.0)
-    pkg_check_modules(PC_RTLSDR QUIET librtlsdr)
-  endif()
+    find_package(PkgConfig)
+    if(CMAKE_VERSION VERSION_LESS 2.8.2)
+      pkg_check_modules(PC_LIBUSB libusb-1.0)
+      pkg_check_modules(PC_RTLSDR librtlsdr)
+    else()
+      pkg_check_modules(PC_LIBUSB QUIET libusb-1.0)
+      pkg_check_modules(PC_RTLSDR QUIET librtlsdr)
+    endif(CMAKE_VERSION VERSION_LESS 2.8.2)
 
   find_path(LIBUSB_INCLUDE_DIR
     NAMES libusb.h
@@ -27,17 +33,15 @@ else (RTLSDR_LIBRARIES AND RTLSDR_INCLUDE_DIRS)
   )
 
   find_library(LIBUSB_LIBRARY
-    NAMES usb-1.0
+    NAMES ${LIBUSB_NAME}
     PATHS ${PC_LIBUSB_LIBRARY_DIRS}
     DOC "libusb library path"
   )
-
   find_path(RTLSDR_INCLUDE_DIR
     NAMES rtl-sdr.h
     PATHS ${PC_RTLSDR_INCLUDE_DIRS} ${RTLSDR_DIR}/include
     DOC "librtlsdr include directory path"
   )
-
   find_library(RTLSDR_LIBRARY
     NAMES rtlsdr
     PATHS ${PC_RTLSDR_LIBRARY_DIRS} ${RTLSDR_DIR}/build/src ${RTLSDR_DIR}/src/.libs
