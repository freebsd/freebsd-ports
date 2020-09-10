--- cmake/freebsd/default_libs.cmake.orig	2020-08-31 16:22:57 UTC
+++ cmake/freebsd/default_libs.cmake
@@ -4,13 +4,13 @@ if (NOT COMPILER_CLANG)
     message (FATAL_ERROR "FreeBSD build is supported only for Clang")
 endif ()
 
-if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "amd64")
-    execute_process (COMMAND ${CMAKE_CXX_COMPILER} --print-file-name=libclang_rt.builtins-x86_64.a OUTPUT_VARIABLE BUILTINS_LIBRARY OUTPUT_STRIP_TRAILING_WHITESPACE)
-else ()
-    execute_process (COMMAND ${CMAKE_CXX_COMPILER} --print-file-name=libclang_rt.builtins-${CMAKE_SYSTEM_PROCESSOR}.a OUTPUT_VARIABLE BUILTINS_LIBRARY OUTPUT_STRIP_TRAILING_WHITESPACE)
-endif ()
+#if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "amd64")
+#    execute_process (COMMAND ${CMAKE_CXX_COMPILER} --print-file-name=libclang_rt.builtins-x86_64.a OUTPUT_VARIABLE BUILTINS_LIBRARY OUTPUT_STRIP_TRAILING_WHITESPACE)
+#else ()
+#    execute_process (COMMAND ${CMAKE_CXX_COMPILER} --print-file-name=libclang_rt.builtins-${CMAKE_SYSTEM_PROCESSOR}.a OUTPUT_VARIABLE BUILTINS_LIBRARY OUTPUT_STRIP_TRAILING_WHITESPACE)
+#endif ()
 
-set (DEFAULT_LIBS "${DEFAULT_LIBS} ${BUILTINS_LIBRARY} ${COVERAGE_OPTION} -lc -lm -lrt -lpthread")
+set (DEFAULT_LIBS "${DEFAULT_LIBS} ${BUILTINS_LIBRARY} ${COVERAGE_OPTION} -lc -lm -lrt -lpthread -lcompiler_rt -lprocstat")
 
 message(STATUS "Default libraries: ${DEFAULT_LIBS}")
 
