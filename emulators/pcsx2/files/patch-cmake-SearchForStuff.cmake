--- cmake/SearchForStuff.cmake.orig	2025-06-23 10:47:03 UTC
+++ cmake/SearchForStuff.cmake
@@ -1,6 +1,8 @@
 #-------------------------------------------------------------------------------
 #                       Search all libraries on the system
 #-------------------------------------------------------------------------------
+list(APPEND CMAKE_MODULE_PATH ${CMAKE_LOCALBASE}/lib/cmake/SDL3_ttf)
+include(PkgConfigHelper)
 find_package(Git)
 
 # Require threads on all OSes.
