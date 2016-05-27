--- swift/cmake/modules/SwiftSharedCMakeConfig.cmake.orig	2016-03-21 17:35:26 UTC
+++ swift/cmake/modules/SwiftSharedCMakeConfig.cmake
@@ -236,7 +236,8 @@ macro(swift_common_standalone_build_conf
   set(CMARK_BUILD_INCLUDE_DIR "${PATH_TO_CMARK_BUILD}/src")
 
   set(CMAKE_INCLUDE_CURRENT_DIR ON)
-  include_directories("${PATH_TO_LLVM_BUILD}/include"
+  include_directories("/usr/local/include"
+                      "${PATH_TO_LLVM_BUILD}/include"
                       "${LLVM_MAIN_INCLUDE_DIR}"
                       "${CLANG_BUILD_INCLUDE_DIR}"
                       "${CLANG_MAIN_INCLUDE_DIR}"
@@ -244,6 +245,7 @@ macro(swift_common_standalone_build_conf
                       "${CMARK_BUILD_INCLUDE_DIR}")
 
   link_directories(
+      "/usr/local/lib"
       "${LLVM_LIBRARY_DIR}"
       # FIXME: if we want to support separate Clang builds and mix different
       # build configurations of Clang and Swift, this line should be adjusted.
