--- cmake/GetMsgpack.cmake.orig	2023-09-26 04:25:05 UTC
+++ cmake/GetMsgpack.cmake
@@ -1,9 +1,13 @@
 find_package(msgpack 3.3.0 EXACT QUIET CONFIG)
+find_package(msgpackc-cxx 4.0.0...<6 QUIET CONFIG)
+find_package(msgpack-cxx 6 QUIET CONFIG)
 
 add_library(msgpack INTERFACE)
 
-if(msgpack_FOUND)
+if(msgpack_FOUND OR msgpackc-cxx_FOUND)
   target_link_libraries(msgpack INTERFACE msgpackc-cxx)
+elseif(msgpack-cxx_FOUND)
+  target_link_libraries(msgpack INTERFACE msgpack-cxx)
 else()
   include(ExternalProject)
   ExternalProject_add(msgpackProject
