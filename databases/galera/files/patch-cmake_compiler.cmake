--- cmake/compiler.cmake.orig	2021-01-12 07:58:44 UTC
+++ cmake/compiler.cmake
@@ -41,6 +41,10 @@ if (CMAKE_BUILD_TYPE STREQUAL "Debug")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_ASSERTIONS")
   # Enable debug sync points
   add_definitions(-DGU_DBUG_ON)
+else()
+  # Due to liberal use of assert() in some modules, make sure that
+  # non-debug builds have -DNDEBUG enabled.
+  add_definitions(-DNDEBUG)
 endif()
 
 if (GALERA_GU_DEBUG_MUTEX)
