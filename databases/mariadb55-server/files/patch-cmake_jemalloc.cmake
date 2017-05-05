--- cmake/jemalloc.cmake.orig	2017-04-30 11:09:29 UTC
+++ cmake/jemalloc.cmake
@@ -22,11 +22,11 @@ MACRO (CHECK_JEMALLOC)
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
