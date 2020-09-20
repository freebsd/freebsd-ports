--- src/cmake/modules/FindPTex.cmake.orig	2020-05-11 03:43:52 UTC
+++ src/cmake/modules/FindPTex.cmake
@@ -70,6 +70,7 @@ else ()
         PATHS
             /usr/include
             /usr/local/include
+            %%LOCALBASE%%/include/ptex
             DOC "The directory where Ptexture.h resides")
     find_library( PTEX_LIBRARY
         NAMES
