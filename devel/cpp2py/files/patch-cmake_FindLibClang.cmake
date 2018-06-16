--- cmake/FindLibClang.cmake.orig	2018-06-04 12:58:14 UTC
+++ cmake/FindLibClang.cmake
@@ -32,6 +32,7 @@ else()
 SET(TRIAL_LIBRARY_PATHS
  ENV LIBRARY_PATH
  ENV LD_INCLUDE_PATH
+ ${CMAKE_INSTALL_PREFIX}/llvm${FREEBSD_LLVM_VER}/lib
  /usr/lib 
  /usr/lib/x86_64-linux-gnu
  /usr/lib/llvm-6.0/lib
