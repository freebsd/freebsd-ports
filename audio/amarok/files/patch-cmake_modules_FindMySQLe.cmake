--- cmake/modules/FindMySQLe.cmake.orig	2021-02-13 22:45:16 UTC
+++ cmake/modules/FindMySQLe.cmake
@@ -51,6 +51,7 @@
 if(NOT MYSQLE_LIBRARIES)
 # mysql-config removed --libmysql-libs, but amarok needs libmysqld other
 # than libmysqlclient to run mysql embedded server.
+    message(STATUS "Looking for mysqld libmysqld..")
     find_library(MYSQLE_LIBRARIES NAMES mysqld libmysqld
         PATHS
             $ENV{MYSQL_DIR}/libmysql_r/.libs
@@ -61,10 +62,14 @@
         PATH_SUFFIXES
             mysql
     )
+    message(STATUS ".. found ${MYSQLE_LIBRARIES}")
+else()
+    message(STATUS "Embedded MySQL libs already set ${MYSQLE_LIBRARIES}")
 endif()
 
 if(PC_MYSQL_VERSION)
     set(MySQLe_VERSION_STRING ${PC_MYSQL_VERSION})
+    message(STATUS ".. version ${MySQLe_VERSION_STRING}")
 endif()
 
 if(MYSQLE_LIBRARIES)
@@ -75,6 +80,13 @@
     #    string(STRIP ${_mysql_libs} _mysql_libs)
     #    set(MYSQLE_LIBRARIES ${_mysql_libs})
     #endif()
+    find_library(_lz4_libraries NAMES lz4 liblz4 PATHS  $ENV{MYSQL_DIR}/lib ${PC_MYSQL_LIBDIR} ${PC_MYSQL_LIBRARY_DIRS})
+    if (_lz4_libraries)
+        message(STATUS ".. adding ${_lz4_libraries}")
+        list(APPEND MYSQLE_LIBRARIES ${_lz4_libraries})
+    endif()
+    message(STATUS ".. compile-checking ${MYSQLE_LIBRARIES}")
+    unset(HAVE_MYSQL_OPT_EMBEDDED_CONNECTION)
     cmake_push_check_state()
     set(CMAKE_REQUIRED_INCLUDES ${MYSQL_INCLUDE_DIR})
     set(CMAKE_REQUIRED_LIBRARIES ${MYSQLE_LIBRARIES})
