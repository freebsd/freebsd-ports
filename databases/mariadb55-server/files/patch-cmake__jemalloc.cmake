--- cmake/jemalloc.cmake.orig	2013-09-20 00:34:22.000000000 +0200
+++ cmake/jemalloc.cmake	2013-09-27 22:46:05.791110010 +0200
@@ -37,9 +37,9 @@
     SET(WITH_JEMALLOC "no")
   ENDIF()
   IF(WITH_JEMALLOC STREQUAL "system" OR WITH_JEMALLOC STREQUAL "yes")
-    CHECK_LIBRARY_EXISTS(jemalloc malloc_stats_print "" HAVE_JEMALLOC)
+    CHECK_LIBRARY_EXISTS(c malloc_stats_print "" HAVE_JEMALLOC)
     IF (HAVE_JEMALLOC)
-      SET(LIBJEMALLOC jemalloc)
+      SET(LIBJEMALLOC c)
     ELSEIF (WITH_JEMALLOC STREQUAL "system")
       MESSAGE(FATAL_ERROR "system jemalloc is not found")
     ELSEIF (WITH_JEMALLOC STREQUAL "yes")
