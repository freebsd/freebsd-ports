--- cmake/cares.cmake.orig	2018-02-01 19:36:08 UTC
+++ cmake/cares.cmake
@@ -30,7 +30,8 @@ if("${gRPC_CARES_PROVIDER}" STREQUAL "mo
     set(gRPC_INSTALL FALSE)
   endif()
 elseif("${gRPC_CARES_PROVIDER}" STREQUAL "package")
-  find_package(c-ares REQUIRED CONFIG)
+  find_package(PkgConfig REQUIRED)
+  pkg_search_module(CARES REQUIRED libcares)
   if(TARGET c-ares::cares)
     set(_gRPC_CARES_LIBRARIES c-ares::cares)
     set(_gRPC_CARES_INCLUDE_DIR ${c-ares_INCLUDE_DIR})
