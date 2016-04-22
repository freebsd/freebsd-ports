--- Libraries/cmake/External_libIGES.cmake.orig	2016-02-14 00:01:30 UTC
+++ Libraries/cmake/External_libIGES.cmake
@@ -1,6 +1,9 @@
 
 #    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../libIGES/
 
+SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
+SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
+
 ExternalProject_Add( LIBIGES
     URL ${CMAKE_CURRENT_SOURCE_DIR}/libIGES-03f6ee919151.zip
 	CMAKE_ARGS -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
