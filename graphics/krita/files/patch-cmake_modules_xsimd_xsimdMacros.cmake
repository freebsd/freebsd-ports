Avoid detecting binutils, especially for FreeBSD 12.x where the base version
gets detected and rejected for being too old. This can be safely removed
after 12.x EOL.

--- cmake/modules/xsimd/xsimdMacros.cmake.orig	2023-10-05 08:16:01 UTC
+++ cmake/modules/xsimd/xsimdMacros.cmake
@@ -60,7 +60,7 @@ macro(xsimd_check_assembler)
 endmacro()
 
 macro(xsimd_check_assembler)
-   execute_process(COMMAND ${CMAKE_CXX_COMPILER} -print-prog-name=as OUTPUT_VARIABLE _as RESULT_VARIABLE _as_result)
+   set(_as_result 1)
    mark_as_advanced(_as)
    mark_as_advanced(_as_result)
    if(_as_result) # error code is 0 == OK
