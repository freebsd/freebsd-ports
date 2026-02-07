--- cmake/toolchain-clang.cmake.orig	2024-10-28 01:17:49 UTC
+++ cmake/toolchain-clang.cmake
@@ -10,8 +10,8 @@ option(CLANG_USE_LIBCXX "Use libc++" OFF)
 option(CLANG_USE_LIBCXX "Use libc++" OFF)
 
 # These are the default values
-set(C_BASE_FLAGS "-march=native -pipe")
-set(CXX_BASE_FLAGS "-march=native -pipe")
+set(C_BASE_FLAGS "${CMAKE_C_FLAGS_RELEASE}")
+set(CXX_BASE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
 
 # For C and C++, the values can be overwritten independently
 if(DEFINED ENV{CXXFLAGS})
