--- cmake/SndFileChecks.cmake.orig	2020-06-20 08:18:11 UTC
+++ cmake/SndFileChecks.cmake
@@ -22,11 +22,6 @@ else ()
 endif ()
 set (SF_COUNT_MAX 0x7fffffffffffffffll)
 
-if (NOT WIN32)
-	find_package (ALSA)
-	find_package (Sndio)
-endif ()
-
 if (VCPKG_TOOLCHAIN AND (NOT CMAKE_VERSION VERSION_LESS 3.15))
 	set (CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)
 endif ()
