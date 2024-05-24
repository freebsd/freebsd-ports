Use pkgconf to set hints for MariaDB, as well.

--- cmake/FindMySQL.cmake.orig	2024-05-08 09:42:08 UTC
+++ cmake/FindMySQL.cmake
@@ -43,7 +43,7 @@ if(PkgConfig_FOUND AND NOT DEFINED MySQL_ROOT)
     find_package(PkgConfig QUIET)
 endif()
 if(PkgConfig_FOUND AND NOT DEFINED MySQL_ROOT)
-    pkg_check_modules(PC_MySQL QUIET "mysqlclient")
+    pkg_search_module(PC_MySQL QUIET "libmariadb" "mysqlclient")
     set(MySQL_include_dir_hints ${PC_MySQL_INCLUDEDIR})
     set(MySQL_library_hints ${PC_MySQL_LIBDIR})
     set(MySQL_library_hints_debug "")
