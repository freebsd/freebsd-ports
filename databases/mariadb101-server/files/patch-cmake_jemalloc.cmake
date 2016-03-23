Fix jemalloc detection on FreeBSD 10.x
Upstream https://github.com/MariaDB/server/pull/140

--- cmake/jemalloc.cmake.orig	2015-12-23 15:33:29 UTC
+++ cmake/jemalloc.cmake
@@ -12,9 +12,16 @@ MACRO(JEMALLOC_TRY_STATIC)
 ENDMACRO()
 
 MACRO(JEMALLOC_TRY_DYNAMIC)
-  SET(libname jemalloc)
   SET(what system)
-  CHECK_LIBRARY_EXISTS(${libname} malloc_stats_print "" HAVE_DYNAMIC_JEMALLOC)
+  IF (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" AND
+      CMAKE_SYSTEM_VERSION STRGREATER "10.0")
+    # Since FreeBSD 10.0 jemalloc is in base libc
+    SET(libname c)
+    SET(HAVE_DYNAMIC_JEMALLOC ON)
+  ELSE()
+    SET(libname jemalloc)
+    CHECK_LIBRARY_EXISTS(${libname} malloc_stats_print "" HAVE_DYNAMIC_JEMALLOC)
+  ENDIF()
 ENDMACRO()
 
 MACRO (CHECK_JEMALLOC)
