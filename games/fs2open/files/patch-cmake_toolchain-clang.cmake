--- cmake/toolchain-clang.cmake.orig	2020-01-25 16:45:09 UTC
+++ cmake/toolchain-clang.cmake
@@ -10,8 +10,8 @@ option(CLANG_ENABLE_ADDRESS_SANITIZER "Enable -fsaniti
 option(CLANG_USE_LIBCXX "Use libc++" OFF)
 
 # These are the default values
-set(C_BASE_FLAGS "-march=native -pipe")
-set(CXX_BASE_FLAGS "-march=native -pipe")
+set(C_BASE_FLAGS "${CMAKE_C_FLAGS_RELEASE}")
+set(CXX_BASE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
 
 # For C and C++, the values can be overwritten independently
 if(DEFINED ENV{CXXFLAGS})
@@ -95,9 +95,6 @@ set(CMAKE_C_FLAGS_RELEASE ${COMPILER_FLAGS_RELEASE})
 
 set(CMAKE_CXX_FLAGS_DEBUG ${COMPILER_FLAGS_DEBUG})
 set(CMAKE_C_FLAGS_DEBUG ${COMPILER_FLAGS_DEBUG})
-
-
-set(CMAKE_EXE_LINKER_FLAGS "")
 
 if (CLANG_USE_LIBCXX)
 	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi")
