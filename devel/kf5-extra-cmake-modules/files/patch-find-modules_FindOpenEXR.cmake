--- find-modules/FindOpenEXR.cmake.orig	2023-12-23 00:45:39 UTC
+++ find-modules/FindOpenEXR.cmake
@@ -43,6 +43,13 @@ set(OpenEXR_DEFINITIONS ${PC_OpenEXR_CFLAGS_OTHER})
 
 set(OpenEXR_DEFINITIONS ${PC_OpenEXR_CFLAGS_OTHER})
 
+find_path(Imath_INCLUDE_DIR ImathMath.h
+   PATHS
+   ${PC_Imath_INCLUDEDIR}
+   ${PC_Imath_INCLUDE_DIRS}
+   PATH_SUFFIXES Imath
+)
+
 find_path(OpenEXR_INCLUDE_DIR ImfRgbaFile.h
    PATHS
    ${PC_OpenEXR_INCLUDEDIR}
@@ -51,7 +58,7 @@ find_path(OpenEXR_INCLUDE_DIR ImfRgbaFile.h
 )
 
 # Required libraries for OpenEXR
-find_library(OpenEXR_HALF_LIBRARY NAMES Half
+find_library(OpenEXR_HALF_LIBRARY NAMES Imath
    PATHS
    ${PC_OpenEXR_LIBDIR}
    ${PC_OpenEXR_LIBRARY_DIRS}
@@ -72,7 +79,7 @@ find_library(OpenEXR_ILMTHREAD_LIBRARY NAMES IlmThread
    ${PC_OpenEXR_LIBRARY_DIRS}
 )
 # This is the actual OpenEXR library
-find_library(OpenEXR_ILMIMF_LIBRARY NAMES IlmImf
+find_library(OpenEXR_ILMIMF_LIBRARY NAMES OpenEXR
    PATHS
    ${PC_OpenEXR_LIBDIR}
    ${PC_OpenEXR_LIBRARY_DIRS}
@@ -108,9 +115,10 @@ find_package_handle_standard_args(OpenEXR
       OpenEXR_IMATH_LIBRARY
       OpenEXR_ILMTHREAD_LIBRARY
       OpenEXR_INCLUDE_DIR
+      Imath_INCLUDE_DIR
    VERSION_VAR OpenEXR_VERSION_STRING)
 
-set(OpenEXR_INCLUDE_DIRS ${OpenEXR_INCLUDE_DIR})
+set(OpenEXR_INCLUDE_DIRS ${Imath_INCLUDE_DIR} ${OpenEXR_INCLUDE_DIR})
 
 include(FeatureSummary)
 set_package_properties(OpenEXR PROPERTIES
