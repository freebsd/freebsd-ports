--- cmake/modules/FindMySQL.cmake.orig	2021-02-13 22:39:45 UTC
+++ cmake/modules/FindMySQL.cmake
@@ -33,7 +33,7 @@ endif()
 # Try searching manually via find_path/find_library,  possibly with hints
 # from pkg-config
 find_package(PkgConfig)
-pkg_check_modules(PC_MYSQL QUIET mysql mariadb)
+pkg_check_modules(PC_MYSQL QUIET mysql mariadb perconaserverclient)
 
 find_path(MYSQL_INCLUDE_DIR mysql.h
     PATHS
