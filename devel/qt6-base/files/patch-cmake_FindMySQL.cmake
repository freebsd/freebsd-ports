Use pkgconf to set hints for MariaDB, as well.

--- cmake/FindMySQL.cmake.orig	2024-11-14 11:02:40 UTC
+++ cmake/FindMySQL.cmake
@@ -47,7 +47,7 @@ if(PkgConfig_FOUND AND NOT DEFINED MySQL_ROOT)
     endif()
 endif()
 if(PkgConfig_FOUND AND NOT DEFINED MySQL_ROOT)
-    pkg_check_modules(PC_MySQL QUIET "mysqlclient")
+    pkg_search_module(PC_MySQL QUIET "libmariadb" "mysqlclient")
     set(MySQL_include_dir_hints ${PC_MySQL_INCLUDEDIR})
     set(MySQL_library_hints ${PC_MySQL_LIBDIR})
     set(MySQL_library_hints_debug "")
