--- CMake/FindOpenJPEG.cmake.orig	2018-11-12 18:42:44 UTC
+++ CMake/FindOpenJPEG.cmake
@@ -21,6 +21,11 @@
 # Try with pkg-config first
 find_package(PkgConfig)
 pkg_check_modules(OPENJPEG libopenjp2)
+if(OPENJPEG_FOUND)
+  set(OPENJPEG_MAJOR_VERSION 2)
+  set(OPENJPEG_INCLUDE_DIR ${OPENJPEG_INCLUDE_DIRS})
+  set(OPENJPEG_LIBRARIES ${OPENJPEG_LDFLAGS})
+endif()
 
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(OpenJPEG REQUIRED_VARS
