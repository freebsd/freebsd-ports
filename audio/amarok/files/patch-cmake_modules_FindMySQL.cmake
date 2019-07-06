--- cmake/modules/FindMySQL.cmake.orig	2019-04-30 03:42:56 UTC
+++ cmake/modules/FindMySQL.cmake
@@ -31,18 +31,20 @@ if(MYSQLCONFIG_EXECUTABLE)
         OUTPUT_STRIP_TRAILING_WHITESPACE
     )
 
-    execute_process(
-        COMMAND ${MYSQLCONFIG_EXECUTABLE} --libmysqld-libs
-        RESULT_VARIABLE MC_return_embedded
-        OUTPUT_VARIABLE MC_MYSQL_EMBEDDED_LIBRARIES
-        OUTPUT_STRIP_TRAILING_WHITESPACE
-    )
-
     if(NOT MC_MYSQL_EMBEDDED_LIBRARIES)
         # At least on OpenSUSE --libmysql-libs doesn't exist, so we just use
         # MYSQL_LIBRARIES for that. We'll see if that's enough when testing
         # below.
-        set(MYSQL_EMBEDDED_LIBRARIES ${MYSQL_LIBRARIES})
+        # mysql-config removed --libmysql-libs, but amarok need libmysqld other
+        # than libmysqlclient to run mysql embedded server.
+        find_library(MYSQL_EMBEDDED_LIBRARIES NAMES mysqld libmysqld
+            PATHS
+                $ENV{MYSQL_DIR}/libmysql_r/.libs
+                $ENV{MYSQL_DIR}/lib
+                $ENV{MYSQL_DIR}/lib/mysql
+            PATH_SUFFIXES
+                mysql
+        )
     else()
         set(MYSQL_EMBEDDED_LIBRARIES ${MC_MYSQL_EMBEDDED_LIBRARIES})
     endif()
@@ -51,7 +53,7 @@ endif()
 # Try searching manually via find_path/find_library,  possibly with hints
 # from pkg-config
 find_package(PkgConfig)
-pkg_check_modules(PC_MYSQL QUIET mysql mariadb)
+pkg_check_modules(PC_MYSQL QUIET mysql mariadb perconaserverclient)
 
 find_path(MYSQL_INCLUDE_DIR mysql.h
     PATHS
@@ -101,6 +103,10 @@ if(MYSQL_EMBEDDED_LIBRARIES)
     #    string(STRIP ${_mysql_libs} _mysql_libs)
     #    set(MYSQL_EMBEDDED_LIBRARIES ${_mysql_libs})
     #endif()
+
+    string(CONCAT MC_MYSQL_LIBRARIES ${MYSQL_LIBRARIES} " -llz4")
+    string(STRIP ${MC_MYSQL_LIBRARIES} MC_MYSQL_LIBRARIES)
+    set(MYSQL_LIBRARIES ${MC_MYSQL_LIBRARIES})
     cmake_push_check_state()
     set(CMAKE_REQUIRED_INCLUDES ${MYSQL_INCLUDE_DIR})
     set(CMAKE_REQUIRED_LIBRARIES ${MYSQL_EMBEDDED_LIBRARIES})
