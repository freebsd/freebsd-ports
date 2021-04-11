--- cmake/modules/FindOpenEXR.cmake.orig	2020-10-28 11:42:28 UTC
+++ cmake/modules/FindOpenEXR.cmake
@@ -23,7 +23,7 @@
 #
 
 find_path(OPENEXR_INCLUDE_DIR
-    OpenEXR/half.h
+    OpenEXR/ImfHeader.h
 HINTS
     "${OPENEXR_LOCATION}"
     "$ENV{OPENEXR_LOCATION}"
@@ -57,11 +57,10 @@ if(OPENEXR_INCLUDE_DIR)
 endif()
 
 foreach(OPENEXR_LIB
-    Half
     Iex
-    Imath
-    IlmImf
+    OpenEXR
     IlmThread
+    Imath
     )
 
     # OpenEXR libraries may be suffixed with the version number, so we search
@@ -87,6 +86,7 @@ endforeach(OPENEXR_LIB)
 # So #include <half.h> works
 list(APPEND OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_DIR})
 list(APPEND OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_DIR}/OpenEXR)
+list(APPEND OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_DIR}/Imath)
 
 include(FindPackageHandleStandardArgs)
 find_package_handle_standard_args(OpenEXR
