--- cmake/toolchain-clang.cmake.orig	2017-08-22 16:56:27 UTC
+++ cmake/toolchain-clang.cmake
@@ -8,8 +8,8 @@ option(CLANG_ENABLE_LEAK_CHECK "Enable -fsanitize=leak
 option(CLANG_ENABLE_ADDRESS_SANITIZER "Enable -fsanitize=address" OFF)
 
 # These are the default values
-set(C_BASE_FLAGS "-march=native -pipe")
-set(CXX_BASE_FLAGS "-march=native -pipe")
+set(C_BASE_FLAGS "${CMAKE_C_FLAGS_RELEASE}")
+set(CXX_BASE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
 
 # For C and C++, the values can be overwritten independently
 if(DEFINED ENV{CXXFLAGS})
@@ -80,7 +80,7 @@ if(SUPPORTS_SHIFT_NEGATIVE_VALUE)
 	set(COMPILER_FLAGS "${COMPILER_FLAGS} -Wno-shift-negative-value")
 endif()
 
-set(COMPILER_FLAGS_RELEASE "-O2 -Wno-unused-variable")
+set(COMPILER_FLAGS_RELEASE "-Wno-unused-variable")
 
 set(COMPILER_FLAGS_DEBUG "-O0 -g -Wshadow")
 
@@ -93,9 +93,6 @@ set(CMAKE_C_FLAGS_RELEASE ${COMPILER_FLAGS_RELEASE})
 
 set(CMAKE_CXX_FLAGS_DEBUG ${COMPILER_FLAGS_DEBUG})
 set(CMAKE_C_FLAGS_DEBUG ${COMPILER_FLAGS_DEBUG})
-
-
-set(CMAKE_EXE_LINKER_FLAGS "")
 
 if (SANITIZE_FLAGS)
 	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZE_FLAGS}")
