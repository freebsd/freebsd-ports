--- cmake/toolchain-gcc.cmake.orig	2021-01-28 12:41:41 UTC
+++ cmake/toolchain-gcc.cmake
@@ -12,8 +12,8 @@ option(GCC_USE_GOLD "Use the gold linker instead of th
 option(GCC_GENERATE_GDB_INDEX "Adds linker option to generate the gdb index for debug builds" OFF)
 
 # These are the default values
-set(C_BASE_FLAGS "-march=native -pipe")
-set(CXX_BASE_FLAGS "-march=native -pipe")
+set(C_BASE_FLAGS "${CMAKE_C_FLAGS_RELEASE}")
+set(CXX_BASE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
 
 # For C and C++, the values can be overwritten independently
 if(DEFINED ENV{CFLAGS})
