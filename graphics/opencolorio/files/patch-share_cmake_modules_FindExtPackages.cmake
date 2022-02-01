--- share/cmake/modules/FindExtPackages.cmake.orig	2021-08-31 10:54:04 UTC
+++ share/cmake/modules/FindExtPackages.cmake
@@ -107,7 +107,7 @@ if(OCIO_BUILD_PYTHON OR OCIO_BUILD_DOCS)
     endif()
 
     # Python
-    find_package(Python ${OCIO_PYTHON_VERSION} REQUIRED
+    find_package(Python ${OCIO_PYTHON_VERSION} EXACT
                  COMPONENTS ${_Python_COMPONENTS})
 
     if(OCIO_BUILD_PYTHON)
