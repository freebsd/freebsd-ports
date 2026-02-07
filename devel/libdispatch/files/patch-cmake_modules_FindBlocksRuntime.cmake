--- cmake/modules/FindBlocksRuntime.cmake.orig	2024-06-13 00:13:26 UTC
+++ cmake/modules/FindBlocksRuntime.cmake
@@ -17,14 +17,14 @@ else()
 else()
   find_path(BlocksRuntime_INCLUDE_DIR
             NAMES
-              Blocks.h
+              Block.h
             HINTS
-              ${CMAKE_INSTALL_FULL_INCLUDEDIR})
+              /usr/include ${CMAKE_INSTALL_FULL_INCLUDEDIR})
   find_library(BlocksRuntime_LIBRARIES
                NAMES
                  BlocksRuntime libBlocksRuntime
                HINTS
-                 ${CMAKE_INSTALL_FULL_LIBDIR})
+                 /usr/lib ${CMAKE_INSTALL_FULL_LIBDIR})
 
   include(FindPackageHandleStandardArgs)
   find_package_handle_standard_args(BlocksRuntime
