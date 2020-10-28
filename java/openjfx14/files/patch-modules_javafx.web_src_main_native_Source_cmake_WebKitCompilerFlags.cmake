--- modules/javafx.web/src/main/native/Source/cmake/WebKitCompilerFlags.cmake.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.web/src/main/native/Source/cmake/WebKitCompilerFlags.cmake
@@ -231,10 +231,6 @@ if (NOT MSVC)
     string(REGEX MATCHALL "-fsanitize=[^ ]*" ENABLED_COMPILER_SANITIZERS ${CMAKE_CXX_FLAGS})
 endif ()
 
-if (UNIX AND NOT APPLE AND NOT ENABLED_COMPILER_SANITIZERS)
-    set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined ${CMAKE_SHARED_LINKER_FLAGS}")
-endif ()
-
 
 # CODE_GENERATOR_PREPROCESSOR_WITH_LINEMARKERS only matters with GCC >= 4.7.0.  Since this
 # version, -P does not output empty lines, which currently breaks make_names.pl in
