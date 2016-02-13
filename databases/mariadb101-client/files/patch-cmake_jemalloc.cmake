# Upstreamed https://github.com/MariaDB/server/pull/140

--- cmake/jemalloc.cmake.orig	2015-12-23 15:33:29 UTC
+++ cmake/jemalloc.cmake
@@ -12,7 +12,12 @@ MACRO(JEMALLOC_TRY_STATIC)
 ENDMACRO()
 
 MACRO(JEMALLOC_TRY_DYNAMIC)
-  SET(libname jemalloc)
+  IF(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" AND 
+    CMAKE_SYSTEM_VERSION STRGREATER "10.0")
+    SET(libname c)
+  ELSE()
+    SET(libname jemalloc)
+  ENDIF()
   SET(what system)
   CHECK_LIBRARY_EXISTS(${libname} malloc_stats_print "" HAVE_DYNAMIC_JEMALLOC)
 ENDMACRO()
