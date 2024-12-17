--- cmake_modules/ThirdpartyToolchain.cmake.orig	2024-12-16 03:22:53 UTC
+++ cmake_modules/ThirdpartyToolchain.cmake
@@ -72,7 +72,7 @@ ExternalProject_Add (orc-format_ep
 # ----------------------------------------------------------------------
 # ORC Format
 ExternalProject_Add (orc-format_ep
-  URL "https://archive.apache.org/dist/orc/orc-format-${ORC_FORMAT_VERSION}/orc-format-${ORC_FORMAT_VERSION}.tar.gz"
+  URL "%%MYSITE%%/orc-format-${ORC_FORMAT_VERSION}.tar.gz"
   URL_HASH SHA256=739fae5ff94b1f812b413077280361045bf92e510ef04b34a610e23a945d8cd5
   CONFIGURE_COMMAND ""
   BUILD_COMMAND     ""
