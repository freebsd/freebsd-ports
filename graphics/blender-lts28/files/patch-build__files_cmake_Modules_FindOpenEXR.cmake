--- build_files/cmake/Modules/FindOpenEXR.cmake.orig	2020-09-25 06:53:19 UTC
+++ build_files/cmake/Modules/FindOpenEXR.cmake
@@ -34,9 +34,8 @@ ENDIF()
 SET(_openexr_libs_ver_init "2.0")
 
 SET(_openexr_FIND_COMPONENTS
-  Half
   Iex
-  IlmImf
+  OpenEXR
   IlmThread
   Imath
 )
