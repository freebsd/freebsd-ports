--- cmake/jemalloc.cmake.orig	2014-10-08 15:19:51.000000000 +0200
+++ cmake/jemalloc.cmake	2014-11-16 20:27:50.032638191 +0100
@@ -22,11 +22,11 @@
       SET(libname jemalloc)
     ENDIF()
 
-    CHECK_LIBRARY_EXISTS(${libname} malloc_stats_print "" HAVE_JEMALLOC)
+    CHECK_LIBRARY_EXISTS(c malloc_stats_print "" HAVE_JEMALLOC)
     SET(CMAKE_REQUIRED_LIBRARIES)
 
     IF (HAVE_JEMALLOC)
-      SET(LIBJEMALLOC ${libname})
+      SET(LIBJEMALLOC c)
     ELSEIF (NOT WITH_JEMALLOC STREQUAL "auto")
       MESSAGE(FATAL_ERROR "${libname} is not found")
     ENDIF()
