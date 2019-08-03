Unbreak with PostgreSQL 11+.  PG_PATCH_VERSION is never used except
for cosmetics (the configuration summary), so it is safe to just
leave it blank.

CMake Error at cmake/FindPG.cmake:74 (LIST):
  LIST index: 2 out of range (-2, 1)

--- cmake/FindPG.cmake.orig	2019-08-03 09:09:29 UTC
+++ cmake/FindPG.cmake
@@ -71,7 +71,6 @@ IF(NOT _retval)
     STRING(REGEX MATCHALL "[0-9]+" PG_VERSION_PARTS "${PG_VERSION_STRING}")
     LIST(GET PG_VERSION_PARTS 0 PG_MAJOR_VERSION)
     LIST(GET PG_VERSION_PARTS 1 PG_MINOR_VERSION)
-    LIST(GET PG_VERSION_PARTS 2 PG_PATCH_VERSION)
 
     # Are extensions supported?
     IF((PG_MAJOR_VERSION GREATER 9) OR ((PG_MAJOR_VERSION EQUAL 9) AND (PG_MINOR_VERSION GREATER 0)))
