--- cmake/jemalloc.cmake.orig	2015-06-17 14:54:11 UTC
+++ cmake/jemalloc.cmake
@@ -24,12 +24,12 @@ MACRO (CHECK_JEMALLOC)
       SET(what system)
     ENDIF()
 
-    CHECK_LIBRARY_EXISTS(${libname} malloc_stats_print "" HAVE_JEMALLOC)
+    CHECK_LIBRARY_EXISTS(c malloc_stats_print "" HAVE_JEMALLOC)
     SET(CMAKE_REQUIRED_LIBRARIES)
 
     IF (HAVE_JEMALLOC)
-      SET(LIBJEMALLOC ${libname})
-      SET(MALLOC_LIBRARY "${what} jemalloc")
+      SET(LIBJEMALLOC c)
+      SET(MALLOC_LIBRARY "system jemalloc")
     ELSEIF (NOT WITH_JEMALLOC STREQUAL "auto")
       MESSAGE(FATAL_ERROR "${libname} is not found")
     ENDIF()
