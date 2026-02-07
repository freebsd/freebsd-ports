--- cmake/version.cmake.orig	2022-09-29 21:46:35 UTC
+++ cmake/version.cmake
@@ -1,9 +1,7 @@
-execute_process(COMMAND git rev-parse --short HEAD RESULT_VARIABLE RETURN_CODE OUTPUT_VARIABLE BUILD_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
+set(BUILD_VERSION 0)
 
-if(RETURN_CODE EQUAL 0)
 	configure_file(
 		"${SRC}"
 		"${DST}"
 		@ONLY
 	)
-endif()
\ No newline at end of file
