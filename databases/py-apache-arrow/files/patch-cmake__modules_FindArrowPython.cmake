--- cmake_modules/FindArrowPython.cmake.orig	2022-06-12 23:30:56 UTC
+++ cmake_modules/FindArrowPython.cmake
@@ -51,7 +51,7 @@ if(ARROW_FOUND)
                      arrow_python
                      arrow/python/api.h
                      ArrowPython
-                     arrow-python)
+                     arrow-python$ENV{FREEBSD_PYTHON_SUFFIX})
   if(NOT ARROW_PYTHON_VERSION)
     set(ARROW_PYTHON_VERSION "${ARROW_VERSION}")
   endif()
