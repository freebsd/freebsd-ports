--- build_files/cmake/Modules/FindPythonLibsUnix.cmake.orig	2020-09-07 10:17:41 UTC
+++ build_files/cmake/Modules/FindPythonLibsUnix.cmake
@@ -34,7 +34,7 @@ IF(NOT PYTHON_ROOT_DIR AND NOT $ENV{PYTHON_ROOT_DIR} S
   SET(PYTHON_ROOT_DIR $ENV{PYTHON_ROOT_DIR})
 ENDIF()

-SET(PYTHON_VERSION 3.7 CACHE STRING "Python Version (major and minor only)")
+SET(PYTHON_VERSION 3.8 CACHE STRING "Python Version (major and minor only)")
 MARK_AS_ADVANCED(PYTHON_VERSION)


