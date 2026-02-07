--- cmake/compiler_clang.cmake.orig	2022-08-22 00:23:26 UTC
+++ cmake/compiler_clang.cmake
@@ -1,7 +1,7 @@
 # CMake fragment
 
 # Clang
-add_definitions("-std=c++11")
+add_definitions("-std=c++14")
 
 # Turn on a lot of warnings, hopefully helping with code quality.
 add_definitions(-Weverything)
