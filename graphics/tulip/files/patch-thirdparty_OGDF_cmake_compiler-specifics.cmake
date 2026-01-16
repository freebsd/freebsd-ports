--- thirdparty/OGDF/cmake/compiler-specifics.cmake.orig	2025-03-31 21:30:23 UTC
+++ thirdparty/OGDF/cmake/compiler-specifics.cmake
@@ -12,12 +12,6 @@ endif()
   set(COIN_LIBRARY_TYPE STATIC)
 endif()
 
-# use native arch (ie, activate things like SSE)
-if(NOT TULIP_BUILD_FOR_APPIMAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang" AND NOT ${CMAKE_SYSTEM_PROCESSOR} MATCHES "^arm")
-  # cannot use add_definitions() here because it does not work with check-sse3.cmake
-  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
-endif()
-
 # set default warning flags for OGDF and tests
 set(available_default_warning_flags "")
 set(available_default_warning_flags_debug "")
