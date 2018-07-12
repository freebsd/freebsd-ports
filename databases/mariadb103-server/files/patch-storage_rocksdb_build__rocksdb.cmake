--- storage/rocksdb/build_rocksdb.cmake.orig	2018-06-25 11:13:28 UTC
+++ storage/rocksdb/build_rocksdb.cmake
@@ -69,15 +69,9 @@ if(ZSTD_FOUND AND (NOT WITH_ROCKSDB_ZSTD
   SET(CMAKE_REQUIRED_LIBRARIES zstd)
   CHECK_FUNCTION_EXISTS(ZDICT_trainFromBuffer ZSTD_VALID)
   UNSET(CMAKE_REQUIRED_LIBRARIES)
-  if (WITH_ROCKSDB_ZSTD STREQUAL "ON" AND NOT ZSTD_VALID)
-    MESSAGE(FATAL_ERROR
-      "WITH_ROCKSDB_ZSTD is ON and ZSTD library was found, but the version needs to be >= 1.1.3")
-  endif()
-  if (ZSTD_VALID)
     add_definitions(-DZSTD)
     include_directories(${ZSTD_INCLUDE_DIR})
     list(APPEND THIRDPARTY_LIBS ${ZSTD_LIBRARY})
-  endif()
 endif()
 
 add_definitions(-DZLIB)
