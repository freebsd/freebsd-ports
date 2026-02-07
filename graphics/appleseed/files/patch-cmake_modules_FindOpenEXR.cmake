--- cmake/modules/FindOpenEXR.cmake.orig	2019-08-31 15:49:01 UTC
+++ cmake/modules/FindOpenEXR.cmake
@@ -53,7 +53,7 @@ find_path (OPENEXR_INCLUDE_DIR NAMES ImfHeader.h
                  /usr/include
 )
 
-find_library (OPENEXR_IMF_LIBRARY NAMES IlmImf-2_3 IlmImf-2_2 IlmImf
+find_library (OPENEXR_IMF_LIBRARY NAMES OpenEXR
               PATH_SUFFIXES lib64 lib
               HINTS ${OPENEXR_ROOT}
                     ${OPENEXR_LOCATION}
@@ -80,7 +80,7 @@ find_package_handle_standard_args (OPENEXR DEFAULT_MSG
 # Set the output variables.
 if (OPENEXR_FOUND)
     set (OPENEXR_INCLUDE_DIRS ${OPENEXR_INCLUDE_DIR})
-    set (OPENEXR_LIBRARIES  ${OPENEXR_IMF_LIBRARY} ${OPENEXR_THREADS_LIBRARY})
+    set (OPENEXR_LIBRARIES  ${OPENEXR_IMF_LIBRARY} ${OPENEXR_THREADS_LIBRARY} -lImath)
 else ()
     set (OPENEXR_INCLUDE_DIRS)
     set (OPENEXR_LIBRARIES)
