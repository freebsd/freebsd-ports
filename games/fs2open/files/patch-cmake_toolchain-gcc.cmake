--- cmake/toolchain-gcc.cmake.orig	2018-06-24 19:15:11 UTC
+++ cmake/toolchain-gcc.cmake
@@ -87,7 +87,7 @@ set(COMPILER_FLAGS "${COMPILER_FLAGS} -W
 
 set(COMPILER_FLAGS "${COMPILER_FLAGS} -Wno-unused-parameter")
 
-set(COMPILER_FLAGS_RELEASE "-O2 -Wno-unused-variable -Wno-unused-but-set-variable -Wno-array-bounds -Wno-empty-body -Wno-clobbered")
+set(COMPILER_FLAGS_RELEASE "-Wno-unused-variable -Wno-unused-but-set-variable -Wno-array-bounds -Wno-empty-body -Wno-clobbered")
 
 set(COMPILER_FLAGS_DEBUG "-O0 -g -Wshadow")
 
