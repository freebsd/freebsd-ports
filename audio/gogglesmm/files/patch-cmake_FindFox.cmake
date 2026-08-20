FreeBSD installs reswrap as ${LOCALBASE}/fox-1.7/reswrap

--- cmake/FindFox.cmake.orig	2026-07-27 00:47:06 UTC
+++ cmake/FindFox.cmake
@@ -153,7 +153,7 @@ if(FOX_USE_EXTERNAL)
                 find_program(FOX_RESWRAP
                     NAMES reswrap reswrap-1.7 reswrap-1.6
                     HINTS ${FOX_PREFIX}/bin
-                    PATH_SUFFIXES bin
+                    PATH_SUFFIXES bin fox-1.7
                 )
 
                 if(FOX_RESWRAP)
