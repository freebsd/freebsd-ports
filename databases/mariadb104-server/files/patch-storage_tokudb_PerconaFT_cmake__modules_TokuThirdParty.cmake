Do NOT use bundled libs, use xz/lzma from base and archivers/snappy from ports

--- storage/tokudb/PerconaFT/cmake_modules/TokuThirdParty.cmake.orig	2019-11-07 05:52:23 UTC
+++ storage/tokudb/PerconaFT/cmake_modules/TokuThirdParty.cmake
@@ -1,5 +1,12 @@
 include(ExternalProject)
 
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
@@ -71,8 +78,15 @@ add_library(lzma STATIC IMPORTED)
 set_target_properties(lzma PROPERTIES IMPORTED_LOCATION
   "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/xz/lib/liblzma.a")
 add_dependencies(lzma build_lzma)
+ENDIF()
 
+IF (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  include_directories("%%LOCALBASE%%/include")
 
+  add_library(snappy SHARED IMPORTED)
+  set_target_properties(snappy PROPERTIES IMPORTED_LOCATION
+    "%%LOCALBASE%%/lib/libsnappy.so")
+ELSE()
 ## add snappy with an external project
 set(SNAPPY_SOURCE_DIR "${TokuDB_SOURCE_DIR}/third_party/snappy-1.1.2" CACHE FILEPATH "Where to find sources for snappy.")
 if (NOT EXISTS "${SNAPPY_SOURCE_DIR}/CMakeLists.txt")
@@ -109,3 +123,4 @@ add_library(snappy STATIC IMPORTED)
 set_target_properties(snappy PROPERTIES IMPORTED_LOCATION
   "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/snappy/lib/libsnappy.a")
 add_dependencies(snappy build_snappy)
+ENDIF()
