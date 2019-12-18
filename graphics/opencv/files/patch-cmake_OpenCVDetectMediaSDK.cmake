--- cmake/OpenCVDetectMediaSDK.cmake.orig	2018-02-23 08:38:33 UTC
+++ cmake/OpenCVDetectMediaSDK.cmake
@@ -19,9 +19,9 @@ else()
     # ???
 endif()
 
-find_path(MFX_INCLUDE mfxdefs.h PATHS "${root}/include" NO_DEFAULT_PATH)
+find_path(MFX_INCLUDE mfxdefs.h PATHS "${root}" PATH_SUFFIXES "include" "include/mfx" NO_DEFAULT_PATH)
 message(STATUS "MFX_INCLUDE: ${MFX_INCLUDE} (${root}/include)")
-find_library(MFX_LIBRARY NAMES mfx PATHS "${root}/lib/${arch}" NO_DEFAULT_PATH)
+find_library(MFX_LIBRARY NAMES mfx PATHS "${root}" PATH_SUFFIXES "lib" "lib/${arch}" NO_DEFAULT_PATH)
 if(MSVC)
     if(MSVC14)
         find_library(MFX_LIBRARY NAMES libmfx_vs2015.lib PATHS "${root}/lib/${arch}" NO_DEFAULT_PATH)
