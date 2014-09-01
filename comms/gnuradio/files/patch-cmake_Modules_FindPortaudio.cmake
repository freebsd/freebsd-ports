--- cmake/Modules/FindPortaudio.cmake.orig	2014-05-16 18:55:22.000000000 -0400
+++ cmake/Modules/FindPortaudio.cmake	2014-08-04 21:57:47.000000000 -0400
@@ -8,6 +8,15 @@
 include(FindPkgConfig)
 pkg_check_modules(PC_PORTAUDIO portaudio-2.0)
 
+if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  message("--- Using Portaudio2 for FreeBSD")
+  set(PORTAUDIO_FOUND_TRUE)
+  set(PORTAUDIO_INCLUDE_DIRS "/usr/local/include/portaudio2")
+  set(PORTAUDIO_LIBRARIES "/usr/local/lib/portaudio2/libportaudio.so")
+  mark_as_advanced(PORTAUDIO_INCLUDE_DIRS PORTAUDIO_LIBRARIES)
+  INCLUDE(FindPackageHandleStandardArgs)
+  FIND_PACKAGE_HANDLE_STANDARD_ARGS(PORTAUDIO DEFAULT_MSG PORTAUDIO_INCLUDE_DIRS PORTAUDIO_LIBRARIES)
+else()
 find_path(PORTAUDIO_INCLUDE_DIRS
   NAMES
     portaudio.h
@@ -50,3 +59,6 @@
     set(PORTAUDIO_FOUND FALSE)
   endif(PORTAUDIO2_FOUND)
 endif()
+
+endif()
+
