--- CMake/Modules/Findhamlib.cmake.orig	2015-11-25 02:16:24 UTC
+++ CMake/Modules/Findhamlib.cmake
@@ -9,6 +9,7 @@
 
 include (LibFindMacros)
 
+
 # pkg-config?
 find_path (__hamlib_pc_path NAMES hamlib.pc
   PATH_SUFFIXES lib/pkgconfig
@@ -26,8 +27,13 @@ if (NOT PC_HAMLIB_STATIC_LIBRARIES)
   if (WIN32)
     set (PC_HAMLIB_STATIC_LIBRARIES hamlib ws2_32)
   else ()
-    set (PC_HAMLIB_STATIC_LIBRARIES hamlib m dl usb)
-  endif ()
+    if (FREEBSD)
+      set (PC_HAMLIB_STATIC_LIBRARIES hamlib m usb)
+      message (STATUS "FREEBSD Hamlib")
+    else()
+      set (PC_HAMLIB_STATIC_LIBRARIES hamlib m dl usb)
+    endif ()
+  endif()
 endif ()
 
 # The libraries
