--- ./cmake/modules/FindPGF.cmake.orig	2013-10-01 06:23:25.000000000 +0000
+++ ./cmake/modules/FindPGF.cmake	2014-01-20 22:29:10.782525688 +0000
@@ -4,24 +4,28 @@
 #  PGF_FOUND            - system has libgf
 #  PGF_INCLUDE_DIRS     - the libpgf include directory
 #  PGF_LIBRARIES        - Link these to use libpgf
-#  PGF_CODEC_VERSION_ID - PGF codec version ID.
 
-FIND_PACKAGE(PkgConfig)
+find_package(PkgConfig)
 
-IF(PKG_CONFIG_FOUND)
+if(PKG_CONFIG_FOUND)
+    pkg_check_modules(PC_PGF QUIET libpgf)
+endif(PKG_CONFIG_FOUND)
 
-    PKG_CHECK_MODULES(PGF libpgf)
+find_path(PGF_INCLUDE_DIRS NAMES PGFimage.h
+  PATHS
+  ${PC_PGF_INCLUDEDIR}
+  ${PC_PGF_INCLUDE_DIRS}
+)
 
-    IF(PGF_FOUND)
-        MESSAGE(STATUS "PGF_INCLUDE_DIRS     = ${PGF_INCLUDE_DIRS}")
-        MESSAGE(STATUS "PGF_INCLUDEDIR       = ${PGF_INCLUDEDIR}")
-        MESSAGE(STATUS "PGF_LIBRARIES        = ${PGF_LIBRARIES}")
-        MESSAGE(STATUS "PGF_LDFLAGS          = ${PGF_LDFLAGS}")
-        MESSAGE(STATUS "PGF_CFLAGS           = ${PGF_CFLAGS}")
-        MESSAGE(STATUS "PGF_VERSION          = ${PGF_VERSION}")
+find_library(PGF_LIBRARIES NAMES pgf
+  PATHS
+  ${PC_PGF_LIBDIR}
+  ${PC_PGF_LIBRARY_DIRS}
+)
 
-        STRING(REPLACE "." "" PGF_CODEC_VERSION_ID "${PGF_VERSION}")
-        MESSAGE(STATUS "PGF_CODEC_VERSION_ID = ${PGF_CODEC_VERSION_ID}")
-    ENDIF(PGF_FOUND)
+include(FindPackageHandleStandardArgs)
+find_package_handle_standard_args(pgf
+  REQUIRED_VARS PGF_LIBRARIES PGF_INCLUDE_DIRS
+)
 
-ENDIF(PKG_CONFIG_FOUND)
+mark_as_advanced(PGF_INCLUDE_DIRS PGF_LIBRARIES)
