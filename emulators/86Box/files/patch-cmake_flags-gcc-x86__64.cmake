--- cmake/flags-gcc-x86_64.cmake.orig	2024-07-26 18:16:26 UTC
+++ cmake/flags-gcc-x86_64.cmake
@@ -14,7 +14,7 @@
 #          Copyright 2021 David Hrdlička.
 #
 
-string(APPEND CMAKE_C_FLAGS_INIT    " -m64 -march=x86-64 -msse2 -mfpmath=sse -mstackrealign")
-string(APPEND CMAKE_CXX_FLAGS_INIT  " -m64 -march=x86-64 -msse2 -mfpmath=sse -mstackrealign")
+string(APPEND CMAKE_C_FLAGS_INIT    " -mstackrealign")
+string(APPEND CMAKE_CXX_FLAGS_INIT  " -mstackrealign")
 
 include(${CMAKE_CURRENT_LIST_DIR}/flags-gcc.cmake)
