--- modules/web/src/main/native/Source/cmake/WebKitCompilerFlags.cmake.orig	2019-07-22 23:29:21 UTC
+++ modules/web/src/main/native/Source/cmake/WebKitCompilerFlags.cmake
@@ -176,10 +176,6 @@ if (NOT MSVC)
     string(REGEX MATCHALL "-fsanitize=[^ ]*" ENABLED_COMPILER_SANITIZERS ${CMAKE_CXX_FLAGS})
 endif ()
 
-if (UNIX AND NOT APPLE AND NOT ENABLED_COMPILER_SANITIZERS)
-    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined ${CMAKE_SHARED_LINKER_FLAGS}")
-endif ()
-
 
 # CODE_GENERATOR_PREPROCESSOR_WITH_LINEMARKERS only matters with GCC >= 4.7.0.  Since this
 # version, -P does not output empty lines, which currently breaks make_names.pl in
