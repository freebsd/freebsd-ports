--- cmake/toolchain-clang.cmake.orig	2018-06-24 19:14:21 UTC
+++ cmake/toolchain-clang.cmake
@@ -80,7 +80,7 @@ if(SUPPORTS_SHIFT_NEGATIVE_VALUE)
 	set(COMPILER_FLAGS "${COMPILER_FLAGS} -Wno-shift-negative-value")
 endif()
 
-set(COMPILER_FLAGS_RELEASE "-O2 -Wno-unused-variable")
+set(COMPILER_FLAGS_RELEASE "-Wno-unused-variable")
 
 set(COMPILER_FLAGS_DEBUG "-O0 -g -Wshadow")
 
