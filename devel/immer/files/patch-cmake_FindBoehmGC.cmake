CMake Error at cmake/FindBoehmGC.cmake:67 (check_c_source_runs):
  Unknown CMake command "check_c_source_runs".

https://github.com/arximboldi/immer/pull/315

--- cmake/FindBoehmGC.cmake.orig	2025-12-02 21:25:10 UTC
+++ cmake/FindBoehmGC.cmake
@@ -52,7 +52,7 @@ if(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
 # For FreeBSD we need to use gc-threaded
 if(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
   # checks if 'gc' supports 'GC_get_parallel' and if it does then use it
-  include(${CMAKE_ROOT}/Modules/CheckCSourceCompiles.cmake)
+  include(${CMAKE_ROOT}/Modules/CheckCSourceRuns.cmake)
   # not sure if this links properly...
   find_library(
     BOEHM_GC_LIBRARIES
