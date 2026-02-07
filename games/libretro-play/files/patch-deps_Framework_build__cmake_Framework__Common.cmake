--- deps/Framework/build_cmake/Framework_Common.cmake.orig	2020-09-13 23:39:14 UTC
+++ deps/Framework/build_cmake/Framework_Common.cmake
@@ -8,8 +8,8 @@ set(CMAKE_MODULE_PATH
 set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
 set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")
 
-set(CMAKE_CXX_STANDARD 17)
-set(CMAKE_CXX_STANDARD_REQUIRED ON)
+
+
 
 set(FRAMEWORK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
 set(PROJECT_INCLUDES)
