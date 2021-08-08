--- storage/innobase/lzo.cmake.orig	2021-08-02 10:58:57 UTC
+++ storage/innobase/lzo.cmake
@@ -17,13 +17,17 @@ SET(WITH_INNODB_LZO AUTO CACHE STRING
 
 MACRO (MYSQL_CHECK_LZO)
   IF (WITH_INNODB_LZO STREQUAL "ON" OR WITH_INNODB_LZO STREQUAL "AUTO")
-    CHECK_INCLUDE_FILES(lzo/lzo1x.h HAVE_LZO_H)
-    CHECK_LIBRARY_EXISTS(lzo2 lzo1x_1_compress "" HAVE_LZO_SHARED_LIB)
-
+    find_path(LZO_INCLUDE NAMES lzo/lzo1x.h)
+    find_library(LZO_LIBRARY NAMES lzo2)
+    get_filename_component(LZO_LIBDIR ${LZO_LIBRARY} DIRECTORY)
+    IF (LZO_INCLUDE)
+      SET(HAVE_LZO_H 1)
+    ENDIF()
+    CHECK_LIBRARY_EXISTS(lzo2 lzo1x_1_compress ${LZO_LIBDIR} HAVE_LZO_SHARED_LIB)
     IF(HAVE_LZO_SHARED_LIB AND HAVE_LZO_H)
       SET(HAVE_INNODB_LZO TRUE)
       ADD_DEFINITIONS(-DHAVE_LZO=1)
-      LINK_LIBRARIES(lzo2)
+      LINK_LIBRARIES(${LZO_LIBRARY})
     ELSE()
       IF (WITH_INNODB_LZO STREQUAL "ON")
         MESSAGE(FATAL_ERROR "Required lzo library is not found")
