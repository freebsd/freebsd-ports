--- cmake/flags-gcc-armv7.cmake.orig	2024-07-26 18:16:08 UTC
+++ cmake/flags-gcc-armv7.cmake
@@ -14,7 +14,4 @@
 #          Copyright 2021 David Hrdlička.
 #
 
-string(APPEND CMAKE_C_FLAGS_INIT    " -march=armv7-a+fp -mfloat-abi=hard")
-string(APPEND CMAKE_CXX_FLAGS_INIT  " -march=armv7-a+fp -mfloat-abi=hard")
-
 include(${CMAKE_CURRENT_LIST_DIR}/flags-gcc.cmake)
