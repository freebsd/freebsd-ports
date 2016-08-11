--- storage/tokudb/PerconaFT/cmake_modules/TokuThirdParty.cmake.orig	2016-02-17 20:59:56 UTC
+++ storage/tokudb/PerconaFT/cmake_modules/TokuThirdParty.cmake
@@ -34,6 +34,13 @@ if (CMAKE_PROJECT_NAME STREQUAL TokuDB)
     endif ()
 endif ()
 
+IF (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  include_directories("/usr/include")
+
+  add_library(lzma SHARED IMPORTED)
+  set_target_properties(lzma PROPERTIES IMPORTED_LOCATION
+    "/usr/lib/liblzma.so")
+ELSE()
 ## add lzma with an external project
 set(xz_configure_opts --with-pic --enable-static)
 if (APPLE)
@@ -105,8 +112,15 @@ add_library(lzma STATIC IMPORTED)
 set_target_properties(lzma PROPERTIES IMPORTED_LOCATION
   "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/xz/lib/liblzma.a")
 add_dependencies(lzma build_lzma)
+ENDIF()
 
+IF (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  include_directories("/usr/local/include")
 
+  add_library(snappy SHARED IMPORTED)
+  set_target_properties(snappy PROPERTIES IMPORTED_LOCATION
+    "/usr/local/lib/libsnappy.so")
+ELSE()
 ## add snappy with an external project
 set(SNAPPY_SOURCE_DIR "${TokuDB_SOURCE_DIR}/third_party/snappy-1.1.2" CACHE FILEPATH "Where to find sources for snappy.")
 if (NOT EXISTS "${SNAPPY_SOURCE_DIR}/CMakeLists.txt")
@@ -140,3 +154,4 @@ add_library(snappy STATIC IMPORTED)
 set_target_properties(snappy PROPERTIES IMPORTED_LOCATION
   "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/snappy/lib/libsnappy.a")
 add_dependencies(snappy build_snappy)
+ENDIF()
