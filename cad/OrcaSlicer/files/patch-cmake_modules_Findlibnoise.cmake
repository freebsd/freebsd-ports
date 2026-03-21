--- cmake/modules/Findlibnoise.cmake.orig	2025-10-02 17:32:12 UTC
+++ cmake/modules/Findlibnoise.cmake
@@ -1,5 +1,5 @@
-find_path(LIBNOISE_INCLUDE_DIR libnoise/noise.h)
-find_library(LIBNOISE_LIBRARY NAMES libnoise libnoise_static liblibnoise_static)
+find_path(LIBNOISE_INCLUDE_DIR noise/noise.h)
+find_library(LIBNOISE_LIBRARY NAMES libnoise.so libnoise_static liblibnoise_static)
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(libnoise DEFAULT_MSG
     LIBNOISE_LIBRARY
@@ -12,4 +12,4 @@ if(libnoise_FOUND)
         IMPORTED_LOCATION "${LIBNOISE_LIBRARY}"
         INTERFACE_INCLUDE_DIRECTORIES "${LIBNOISE_INCLUDE_DIR}"
     )
-endif()
\ No newline at end of file
+endif()
