--- cmake/freebsd/toolchain-x86_64.cmake.orig	2021-12-26 09:29:33 UTC
+++ cmake/freebsd/toolchain-x86_64.cmake
@@ -1,8 +1,8 @@
 set (CMAKE_SYSTEM_NAME "FreeBSD")
 set (CMAKE_SYSTEM_PROCESSOR "x86_64")
-set (CMAKE_C_COMPILER_TARGET "x86_64-pc-freebsd11")
-set (CMAKE_CXX_COMPILER_TARGET "x86_64-pc-freebsd11")
-set (CMAKE_ASM_COMPILER_TARGET "x86_64-pc-freebsd11")
+set (CMAKE_C_COMPILER_TARGET "x86_64-pc-freebsd13")
+set (CMAKE_CXX_COMPILER_TARGET "x86_64-pc-freebsd13")
+set (CMAKE_ASM_COMPILER_TARGET "x86_64-pc-freebsd13")
 set (CMAKE_SYSROOT "${CMAKE_CURRENT_LIST_DIR}/../../contrib/sysroot/freebsd-x86_64")
 
 set (CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)  # disable linkage check - it doesn't work in CMake
