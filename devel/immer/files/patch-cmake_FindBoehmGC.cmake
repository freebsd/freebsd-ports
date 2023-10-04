--- cmake/FindBoehmGC.cmake.orig	2023-10-04 09:47:41 UTC
+++ cmake/FindBoehmGC.cmake
@@ -57,7 +57,7 @@ IF (${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
 IF (${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
   # checks if 'gc' supports 'GC_get_parallel' and if it does
   # then use it
-  INCLUDE(${CMAKE_ROOT}/Modules/CheckCSourceCompiles.cmake)
+  INCLUDE(${CMAKE_ROOT}/Modules/CheckCSourceRuns.cmake)
   # not sure if this links properly...
   FIND_LIBRARY(BOEHM_GC_LIBRARIES NAMES gc
     HINTS ${PC_BDW_GC_LIBDIR} ${PC_BDW_GC_LIBRARY_DIRS})
