--- cmake/version.cmake.orig	2017-10-13 23:15:05 UTC
+++ cmake/version.cmake
@@ -1,7 +1,4 @@
-execute_process(COMMAND git log --oneline COMMAND wc -l OUTPUT_VARIABLE BUILD_NUMBER OUTPUT_STRIP_TRAILING_WHITESPACE)
-if(BUILD_NUMBER STREQUAL "")
-	set(BUILD_NUMBER 0)
-endif()
+set(BUILD_NUMBER 0)
 
 configure_file(
 	"${SRC}"
