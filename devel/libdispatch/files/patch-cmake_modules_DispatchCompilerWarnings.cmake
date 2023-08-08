--- cmake/modules/DispatchCompilerWarnings.cmake.orig	2021-09-17 04:54:52 UTC
+++ cmake/modules/DispatchCompilerWarnings.cmake
@@ -2,7 +2,6 @@ else()
 if("${CMAKE_C_SIMULATE_ID}" STREQUAL "MSVC")
   # TODO: someone needs to provide the msvc equivalent warning flags
 else()
-  add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Werror>)
   add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wall>)
   add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wextra>)
 
