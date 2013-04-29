--- cmake/Modules/FindPortaudio.cmake.orig	2013-01-08 15:56:55.000000000 -0500
+++ cmake/Modules/FindPortaudio.cmake	2013-04-23 07:47:40.000000000 -0500
@@ -6,7 +6,13 @@
 #  PORTAUDIO_LIBRARIES - Link these to use Portaudio
 
 include(FindPkgConfig)
-pkg_check_modules(PC_PORTAUDIO portaudio)
+if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  message( "--- Using Portaudio2 for FreeBSD")
+  set(PORTAUDIO_FOUND TRUE)
+  set(PORTAUDIO_INCLUDE_DIRS "%%LOCALBASE%%/include/portaudio2")
+  set(PORTAUDIO_LIBRARIES "%%LOCALBASE%%/lib/portaudio2/libportaudio.so")
+else()
+  pkg_check_modules(PC_PORTAUDIO portaudio)
 
 find_path(PORTAUDIO_INCLUDE_DIRS
   NAMES
@@ -28,7 +34,7 @@
   HINTS
     ${PC_PORTAUDIO_LIBDIR}
 )
-
+endif()
 mark_as_advanced(PORTAUDIO_INCLUDE_DIRS PORTAUDIO_LIBRARIES)
 
 INCLUDE(FindPackageHandleStandardArgs)
