--- packages/clib/cmake/FindLibUUID.cmake.orig	2020-06-28 13:21:56 UTC
+++ packages/clib/cmake/FindLibUUID.cmake
@@ -25,9 +25,8 @@ if(UUID_CONFIG)
 
     string(REPLACE "-l" "" LIBUUID_LIB ${LIBUUID_LIBFLAG})
     find_library(UUID_LIBRARY
-		 NAMES ${LIBUUID_LIB}
-		 PATHS ${LIBUUID_LIBRARY_DIR}
-		 NO_DEFAULT_PATH)
+		 NAMES ossp-uuid
+		 PATHS ${LIBUUID_LIBRARY_DIR})
     if(NOT UUID_LIBRARY AND LIBUUID_LIB MATCHES "ossp")
       find_library(UUID_LIBRARY
 		   NAMES ${LIBUUID_LIB}
