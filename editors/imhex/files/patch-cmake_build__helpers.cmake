--- cmake/build_helpers.cmake.orig	2021-09-10 13:54:59 UTC
+++ cmake/build_helpers.cmake
@@ -37,7 +37,7 @@ macro(findLibraries)
     # Find packages
     find_package(PkgConfig REQUIRED)
 
-    find_package(mbedTLS REQUIRED)
+    find_library(mbedTLS mbedtls REQUIRED)
 
     pkg_search_module(CAPSTONE REQUIRED capstone)
 
@@ -48,6 +48,8 @@ macro(findLibraries)
         message(STATUS ${PYTHON_VERSION_MAJOR_MINOR})
         message(FATAL_ERROR "No valid version of Python 3 was found.")
     endif()
+
+    find_package(CURL REQUIRED)
 
     string(REPLACE "." ";" PYTHON_VERSION_MAJOR_MINOR ${Python_VERSION})
 
