--- cmake/modules/DispatchCompilerWarnings.cmake.orig	2026-05-01 02:25:26 UTC
+++ cmake/modules/DispatchCompilerWarnings.cmake
@@ -6,7 +6,6 @@ else()
   # so that we can use __popcnt64
   add_compile_options($<$<COMPILE_LANGUAGE:C,CXX>:-fms-extensions>)
 else()
-  add_compile_options($<$<COMPILE_LANGUAGE:C,CXX>:-Werror>)
   add_compile_options($<$<COMPILE_LANGUAGE:C,CXX>:-Wall>)
   add_compile_options($<$<COMPILE_LANGUAGE:C,CXX>:-Wextra>)
 
