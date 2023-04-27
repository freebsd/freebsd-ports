--- share/cmake/modules/FindExtPackages.cmake.orig	2023-01-06 02:05:59 UTC
+++ share/cmake/modules/FindExtPackages.cmake
@@ -69,7 +69,7 @@ find_package(Imath 3.0 REQUIRED)
 # ZLIB 1.2.13 is used since it fixes a critical vulnerability.
 # See https://nvd.nist.gov/vuln/detail/CVE-2022-37434
 # See https://github.com/madler/zlib/releases/tag/v1.2.13
-set(_ZLIB_FIND_VERSION "1.2.13")
+set(_ZLIB_FIND_VERSION "1.2.12")
 set(_ZLIB_ExternalProject_VERSION ${_ZLIB_FIND_VERSION})
 
 if(NOT OCIO_INSTALL_EXT_PACKAGES STREQUAL ALL)
@@ -178,7 +178,7 @@ if(OCIO_BUILD_PYTHON OR OCIO_BUILD_DOCS)
     endif()
 
     # Python
-    find_package(Python ${OCIO_PYTHON_VERSION} REQUIRED
+    find_package(Python ${OCIO_PYTHON_VERSION} EXACT
                  COMPONENTS ${_Python_COMPONENTS})
 
     if(OCIO_BUILD_PYTHON)
