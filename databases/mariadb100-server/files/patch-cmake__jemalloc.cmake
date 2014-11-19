--- cmake/jemalloc.cmake.orig	2014-09-25 00:29:47.000000000 +0200
+++ cmake/jemalloc.cmake	2014-09-27 10:05:48.000000000 +0200
@@ -24,12 +24,12 @@
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
