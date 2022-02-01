--- src/cmake/modules/FindPtex.cmake.orig	2021-10-31 17:08:10 UTC
+++ src/cmake/modules/FindPtex.cmake
@@ -70,6 +70,7 @@ else ()
         PATHS
             /usr/include
             /usr/local/include
+            /usr/local/include/ptex
             DOC "The directory where Ptexture.h resides")
     find_library( PTEX_LIBRARY
         NAMES
