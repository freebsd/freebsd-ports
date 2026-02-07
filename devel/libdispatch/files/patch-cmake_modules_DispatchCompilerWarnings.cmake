--- cmake/modules/DispatchCompilerWarnings.cmake.orig	2024-06-13 00:13:26 UTC
+++ cmake/modules/DispatchCompilerWarnings.cmake
@@ -6,7 +6,6 @@ else()
   # so that we can use __popcnt64
   add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-fms-extensions>)
 else()
-  add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Werror>)
   add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wall>)
   add_compile_options($<$<OR:$<COMPILE_LANGUAGE:C>,$<COMPILE_LANGUAGE:CXX>>:-Wextra>)
 
