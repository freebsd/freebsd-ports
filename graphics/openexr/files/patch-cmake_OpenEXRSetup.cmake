--- cmake/OpenEXRSetup.cmake.orig	2025-10-07 15:22:39 UTC
+++ cmake/OpenEXRSetup.cmake
@@ -100,7 +100,7 @@ set(CMAKE_INCLUDE_CURRENT_DIR ON)
 # Suffix for debug configuration libraries
 # (if you should choose to install those)
 # Don't override if the user has set it and don't save it in the cache
-if (NOT CMAKE_DEBUG_POSTFIX)
+if (NOT DEFINED CMAKE_DEBUG_POSTFIX)
   set(CMAKE_DEBUG_POSTFIX "_d")
 endif()
 
