--- cmake/modules/FindOpenEXR.cmake.orig	2021-02-03 13:36:49 UTC
+++ cmake/modules/FindOpenEXR.cmake
@@ -24,9 +24,6 @@ find_path(_OPENEXR_LIB_DIR OpenEXR
 set(OpenEXR_LIB_DIR ${_OPENEXR_LIB_DIR})
 mark_as_advanced(OpenEXR_LIB_DIR)
 
-find_library(_OPENEXR_LIBRARY_IMIMF IlmImf
-  HINTS ENV OPENEXR_LIB_DIR)
-set(OpenEXR_LIBRARY ${OpenEXR_LIBRARY} ${_OPENEXR_LIBRARY_IMIMF})
 find_library(_OPENEXR_LIBRARY_IMATH Imath
   HINTS ENV OPENEXR_LIB_DIR)
 set(OpenEXR_LIBRARY ${OpenEXR_LIBRARY} ${_OPENEXR_LIBRARY_IMATH})
