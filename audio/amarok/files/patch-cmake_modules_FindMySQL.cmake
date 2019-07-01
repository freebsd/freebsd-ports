--- cmake/modules/FindMySQL.cmake.orig	2019-06-14 07:24:31 UTC
+++ cmake/modules/FindMySQL.cmake
@@ -31,21 +31,7 @@ if(MYSQLCONFIG_EXECUTABLE)
         OUTPUT_STRIP_TRAILING_WHITESPACE
     )
 
-    execute_process(
-        COMMAND ${MYSQLCONFIG_EXECUTABLE} --libmysqld-libs
-        RESULT_VARIABLE MC_return_embedded
-        OUTPUT_VARIABLE MC_MYSQL_EMBEDDED_LIBRARIES
-        OUTPUT_STRIP_TRAILING_WHITESPACE
-    )
-
-    if(NOT MC_MYSQL_EMBEDDED_LIBRARIES)
-        # At least on OpenSUSE --libmysql-libs doesn't exist, so we just use
-        # MYSQL_LIBRARIES for that. We'll see if that's enough when testing
-        # below.
-        set(MYSQL_EMBEDDED_LIBRARIES ${MYSQL_LIBRARIES})
-    else()
-        set(MYSQL_EMBEDDED_LIBRARIES ${MC_MYSQL_EMBEDDED_LIBRARIES})
-    endif()
+    set(MYSQL_EMBEDDED_LIBRARIES "-L/usr/local/lib/mysql" -lmysqld -llz4)
 endif()
 
 # Try searching manually via find_path/find_library,  possibly with hints
