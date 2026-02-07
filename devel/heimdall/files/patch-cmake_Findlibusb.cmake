--- cmake/Findlibusb.cmake.orig	2017-05-11 18:34:25 UTC
+++ cmake/Findlibusb.cmake
@@ -6,7 +6,7 @@ find_path(LIBUSB_INCLUDE_DIR
         /opt/local/include
         /usr/include
     PATH_SUFFIXES
-        libusb-1.0
+        libusb
 )
 
 if (libusb_USE_STATIC_LIBS AND NOT MSVC)
@@ -19,7 +19,7 @@ endif (libusb_USE_STATIC_LIBS AND NOT MS
 
 find_library(LIBUSB_LIBRARY
     NAMES
-        ${LIBUSB_LIB_PREFIX}usb-1.0${LIBUSB_LIB_SUFFIX} ${LIBUSB_LIB_PREFIX}usb${LIBUSB_LIB_SUFFIX}
+        ${LIBUSB_LIB_PREFIX}usb${LIBUSB_LIB_SUFFIX} ${LIBUSB_LIB_PREFIX}usb${LIBUSB_LIB_SUFFIX}
     PATHS
         /usr/local/lib
         /opt/local/lib
