--- src/cmake/External_STEPCode.cmake.orig	2016-02-14 00:01:30 UTC
+++ src/cmake/External_STEPCode.cmake
@@ -8,6 +8,9 @@ ELSE()
     SET( SC_SHARED ON )
 ENDIF()
 
+SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
+SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
+
 ExternalProject_Add( STEPCODE
 	URL ${CMAKE_CURRENT_SOURCE_DIR}/stepcode-7dcd6ef3418a.zip
 	CMAKE_ARGS -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
@@ -37,4 +40,4 @@ SET( STEPCODE_BINARY_DIR ${BINARY_DIR} )
 # Consequently, force Debug so it installs in ../sc-install directory
 # instead of /usr/local/lib.
 #
-# SC's own programs fail to build with -DSC_BUILD_SHARED_LIBS=OFF
\ No newline at end of file
+# SC's own programs fail to build with -DSC_BUILD_SHARED_LIBS=OFF
