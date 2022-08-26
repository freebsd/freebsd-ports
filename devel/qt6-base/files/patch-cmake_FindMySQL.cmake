Help cmake figure out the locations of the headers when mariadb is used.

--- cmake/FindMySQL.cmake.orig	2021-10-20 11:54:23 UTC
+++ cmake/FindMySQL.cmake
@@ -19,7 +19,7 @@
 #     The mysql client library
 
 find_package(PkgConfig QUIET)
-pkg_check_modules(PC_MySQL QUIET mysqlclient)
+pkg_search_module(PC_MySQL QUIET mysqlclient mariadb)
 
 find_path(MySQL_INCLUDE_DIR
           NAMES mysql.h
