--- CMake/FollyFunctions.cmake.orig	2026-01-19 20:28:13 UTC
+++ CMake/FollyFunctions.cmake
@@ -476,7 +476,7 @@ function(folly_add_library)
   endif()
 
   # 2. Create STATIC library (individual .a file for granular linking)
-  add_library(${_target_name} STATIC $<TARGET_OBJECTS:${_obj_target}>)
+  add_library(${_target_name} $<TARGET_OBJECTS:${_obj_target}>)
   set_property(TARGET ${_target_name} PROPERTY VERSION ${PACKAGE_VERSION})
 
   target_include_directories(${_target_name}
