--- cmake/OptimalOptions.cmake.orig	2020-08-24 06:27:21 UTC
+++ cmake/OptimalOptions.cmake
@@ -1,7 +1,6 @@
 
 # Set optimal options for gcc:
 if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
-	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
 	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
 ENDIF()
 
