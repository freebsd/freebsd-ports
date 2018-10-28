--- storage/rocksdb/build_rocksdb.cmake.orig	2018-10-02 09:45:43 UTC
+++ storage/rocksdb/build_rocksdb.cmake
@@ -69,10 +69,6 @@ if(ZSTD_FOUND AND (NOT WITH_ROCKSDB_ZSTD
   SET(CMAKE_REQUIRED_LIBRARIES zstd)
   CHECK_FUNCTION_EXISTS(ZDICT_trainFromBuffer ZSTD_VALID)
   UNSET(CMAKE_REQUIRED_LIBRARIES)
-  if (WITH_ROCKSDB_ZSTD STREQUAL "ON" AND NOT ZSTD_VALID)
-    MESSAGE(FATAL_ERROR
-      "WITH_ROCKSDB_ZSTD is ON and ZSTD library was found, but the version needs to be >= 1.1.3")
-  endif()
   if (ZSTD_VALID)
     add_definitions(-DZSTD)
     include_directories(${ZSTD_INCLUDE_DIR})
