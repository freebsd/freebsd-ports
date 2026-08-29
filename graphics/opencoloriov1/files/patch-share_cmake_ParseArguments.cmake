--- share/cmake/ParseArguments.cmake.orig	2019-03-28 05:12:57 UTC
+++ share/cmake/ParseArguments.cmake
@@ -24,7 +24,7 @@
 # Downloaded from: http://www.itk.org/Wiki/CMakeMacroParseArguments
 #
 
-cmake_minimum_required(VERSION 2.4.7)
+cmake_minimum_required(VERSION 2.4.7...9.9.9)
 
 MACRO(PARSE_ARGUMENTS prefix arg_names option_names)
     SET(DEFAULT_ARGS)
