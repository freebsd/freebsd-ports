--- cmake_modules/ThirdpartyToolchain.cmake.orig	2025-09-29 07:31:58 UTC
+++ cmake_modules/ThirdpartyToolchain.cmake
@@ -141,7 +141,7 @@ else()
   set(ORC_FORMAT_SOURCE_URL "$ENV{ORC_FORMAT_URL}")
   message(STATUS "Using ORC_FORMAT_URL: ${ORC_FORMAT_SOURCE_URL}")
 else()
-  set(ORC_FORMAT_SOURCE_URL "https://www.apache.org/dyn/closer.lua/orc/orc-format-${ORC_FORMAT_VERSION}/orc-format-${ORC_FORMAT_VERSION}.tar.gz?action=download" )
+  set(ORC_FORMAT_SOURCE_URL "%%MYSITE%%/orc-format-${ORC_FORMAT_VERSION}.tar.gz" )
   message(STATUS "Using DEFAULT URL: ${ORC_FORMAT_SOURCE_URL}")
 endif()
 ExternalProject_Add (orc-format_ep
