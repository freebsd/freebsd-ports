--- cmake/flags-gcc-aarch64.cmake.orig	2024-07-26 18:14:45 UTC
+++ cmake/flags-gcc-aarch64.cmake
@@ -14,7 +14,4 @@
 #          Copyright 2021 David Hrdlička.
 #
 
-string(APPEND CMAKE_C_FLAGS_INIT    " -march=armv8-a")
-string(APPEND CMAKE_CXX_FLAGS_INIT  " -march=armv8-a")
-
 include(${CMAKE_CURRENT_LIST_DIR}/flags-gcc.cmake)
