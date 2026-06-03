--- cmake/modules/Findlibnoise.cmake.orig	2026-03-22 17:56:38 UTC
+++ cmake/modules/Findlibnoise.cmake
@@ -1,6 +1,6 @@
-find_path(LIBNOISE_INCLUDE_DIR libnoise/noise.h)
-find_library(LIBNOISE_LIBRARY_RELEASE NAMES libnoise libnoise_static liblibnoise_static)
-find_library(LIBNOISE_LIBRARY_DEBUG NAMES libnoised libnoise_staticd liblibnoise_staticd)
+find_path(LIBNOISE_INCLUDE_DIR noise/noise.h)
+find_library(LIBNOISE_LIBRARY_RELEASE NAMES libnoise.so libnoise_static liblibnoise_static)
+find_library(LIBNOISE_LIBRARY_DEBUG NAMES libnoised.so libnoise_staticd liblibnoise_staticd)
 
 set(libnoise_LIB_FOUND FALSE)
 if (LIBNOISE_LIBRARY_RELEASE OR LIBNOISE_LIBRARY_DEBUG)
@@ -38,4 +38,4 @@ if(libnoise_FOUND)
         set_property(TARGET noise::noise APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
         set_target_properties(noise::noise PROPERTIES IMPORTED_LOCATION_DEBUG ${LIBNOISE_LIBRARY_DEBUG})
     endif ()
-endif()
\ No newline at end of file
+endif()
