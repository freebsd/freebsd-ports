--- cmake/build_configurations/compiler_options.cmake.orig	2016-08-25 11:52:06 UTC
+++ cmake/build_configurations/compiler_options.cmake
@@ -43,7 +43,7 @@ IF(UNIX)  
 
   # Default GCC flags
   IF(CMAKE_COMPILER_IS_GNUCC)
-    SET(COMMON_C_FLAGS "-fabi-version=2 -fno-omit-frame-pointer -fno-strict-aliasing")
+    SET(COMMON_C_FLAGS "-fno-omit-frame-pointer -fno-strict-aliasing")
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
       STRING_PREPEND(COMMON_C_FLAGS "-fno-inline ")
@@ -68,7 +68,7 @@ IF(UNIX)  
     ENDIF()
   ENDIF()
   IF(CMAKE_COMPILER_IS_GNUCXX)
-    SET(COMMON_CXX_FLAGS               "-fabi-version=2 -fno-omit-frame-pointer -fno-strict-aliasing")
+    SET(COMMON_CXX_FLAGS               "-fno-omit-frame-pointer -fno-strict-aliasing")
     # GCC 6 has C++14 as default, set it explicitly to the old default.
     EXECUTE_PROCESS(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                     OUTPUT_VARIABLE GXX_VERSION)
