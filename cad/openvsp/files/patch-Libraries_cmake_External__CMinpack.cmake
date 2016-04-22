--- Libraries/cmake/External_CMinpack.cmake.orig	2016-02-14 00:01:30 UTC
+++ Libraries/cmake/External_CMinpack.cmake
@@ -1,3 +1,6 @@
+SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lm -fPIC")
+SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm -fPIC")
+
 ExternalProject_Add( CMINPACK
     URL ${CMAKE_CURRENT_SOURCE_DIR}/cminpack-1.3.3.tar.gz
     CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
@@ -8,4 +11,4 @@ ExternalProject_Add( CMINPACK
         -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
 )
 ExternalProject_Get_Property( CMINPACK BINARY_DIR INSTALL_DIR )
-SET( CMINPACK_INSTALL_DIR ${INSTALL_DIR} )
\ No newline at end of file
+SET( CMINPACK_INSTALL_DIR ${INSTALL_DIR} )
