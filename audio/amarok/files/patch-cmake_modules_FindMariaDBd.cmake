--- cmake/modules/FindMariaDBd.cmake.orig	2026-01-17 10:51:16 UTC
+++ cmake/modules/FindMariaDBd.cmake
@@ -32,7 +32,7 @@ if(MYSQLCONFIG_EXECUTABLE)
 
 if(MYSQLCONFIG_EXECUTABLE)
     execute_process(
-        COMMAND ${MYSQLCONFIG_EXECUTABLE} --libmysqld-libs
+        COMMAND ${MYSQLCONFIG_EXECUTABLE} --libs
         RESULT_VARIABLE MC_return_embedded
         OUTPUT_VARIABLE MC_MYSQLE_LIBRARIES
         OUTPUT_STRIP_TRAILING_WHITESPACE
