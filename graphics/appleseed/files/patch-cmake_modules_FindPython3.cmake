--- cmake/modules/FindPython3.cmake.orig	2019-08-31 15:49:01 UTC
+++ cmake/modules/FindPython3.cmake
@@ -39,19 +39,13 @@
 
 include (FindPackageHandleStandardArgs)
 
-find_path (PYTHON3_INCLUDE_DIR NAMES Python.h)
-find_library (PYTHON3_LIBRARY NAMES python3)
+find_package(PythonInterp) # provides Python major/minor version vars
+find_package(PythonLibs)
 
-# Handle the QUIETLY and REQUIRED arguments and set PYTHON3_FOUND.
-find_package_handle_standard_args (PYTHON3 DEFAULT_MSG
-    PYTHON3_INCLUDE_DIR
-    PYTHON3_LIBRARY
-)
-
 # Set the output variables.
-if (PYTHON3_FOUND)
-    set (PYTHON3_INCLUDE_DIRS ${PYTHON3_INCLUDE_DIR})
-    set (PYTHON3_LIBRARIES ${PYTHON3_LIBRARY})
+if (PYTHONLIBS_FOUND)
+    set (PYTHON3_INCLUDE_DIRS ${PYTHON_INCLUDE_DIR})
+    set (PYTHON3_LIBRARIES ${PYTHON_LIBRARIES})
 else ()
     set (PYTHON3_INCLUDE_DIRS)
     set (PYTHON3_LIBRARIES)
