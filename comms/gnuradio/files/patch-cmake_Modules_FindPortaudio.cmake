--- cmake/Modules/FindPortaudio.cmake.orig	2012-04-25 11:12:33.000000000 -0500
+++ cmake/Modules/FindPortaudio.cmake	2014-03-02 20:19:36.000000000 -0500
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
