--- src/cmake/modules/FindPtex.cmake.orig	2021-07-01 18:54:28 UTC
+++ src/cmake/modules/FindPtex.cmake
@@ -70,6 +70,7 @@ else ()
         PATHS
             /usr/include
             /usr/local/include
+            %%LOCALBASE%%/include/ptex
             DOC "The directory where Ptexture.h resides")
     find_library( PTEX_LIBRARY
         NAMES
