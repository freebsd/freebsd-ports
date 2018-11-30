--- cmake/cares.cmake.orig	2018-09-24 23:51:30 UTC
+++ cmake/cares.cmake
@@ -31,7 +31,8 @@ if("${gRPC_CARES_PROVIDER}" STREQUAL "module")
   endif()
 elseif("${gRPC_CARES_PROVIDER}" STREQUAL "package")
   # Use "CONFIG" as there is no built-in cmake module for c-ares.
-  find_package(c-ares REQUIRED CONFIG)
+  find_package(PkgConfig REQUIRED)
+  pkg_search_module(CARES REQUIRED libcares)
   if(TARGET c-ares::cares)
     set(_gRPC_CARES_LIBRARIES c-ares::cares)
     set(_gRPC_CARES_INCLUDE_DIR ${c-ares_INCLUDE_DIR})
