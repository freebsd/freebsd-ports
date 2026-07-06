Backport [1] to fix build with Qt 6.10.

[1] https://github.com/PCSX2/pcsx2/commit/8dffc857079e942ca77b091486c20c3c6530e4ed

--- cmake/SearchForStuff.cmake.orig	2025-06-29 19:47:12 UTC
+++ cmake/SearchForStuff.cmake
@@ -1,6 +1,8 @@
 #-------------------------------------------------------------------------------
 #                       Search all libraries on the system
 #-------------------------------------------------------------------------------
+list(APPEND CMAKE_MODULE_PATH ${CMAKE_LOCALBASE}/lib/cmake/SDL3_ttf)
+include(PkgConfigHelper)
 find_package(Git)
 
 # Require threads on all OSes.
