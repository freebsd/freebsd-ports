Upstreamed https://github.com/MariaDB/server/pull/139

--- cmake/jemalloc.cmake.orig	2015-12-16 16:05:44 UTC
+++ cmake/jemalloc.cmake
@@ -20,11 +20,21 @@ MACRO (CHECK_JEMALLOC)
       SET(CMAKE_REQUIRED_LIBRARIES pthread dl m)
       SET(what bundled)
     ELSE()
-      SET(libname jemalloc)
+      IF(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" AND
+        CMAKE_SYSTEM_VERSION STRGREATER "10.0")
+        SET(libname c)
+      ELSE()
+        SET(libname jemalloc)
+      ENDIF()
       SET(what system)
     ENDIF()
 
-    CHECK_LIBRARY_EXISTS(${libname} malloc_stats_print "" HAVE_JEMALLOC)
+    IF(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" AND
+      CMAKE_SYSTEM_VERSION STRGREATER "10.0")
+      SET(HAVE_JEMALLOC ON)
+    ELSE()
+      CHECK_LIBRARY_EXISTS(${libname} malloc_stats_print "" HAVE_JEMALLOC)
+    ENDIF()
     SET(CMAKE_REQUIRED_LIBRARIES)
 
     IF (HAVE_JEMALLOC)
