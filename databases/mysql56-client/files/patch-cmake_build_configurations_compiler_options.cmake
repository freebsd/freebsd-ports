--- cmake/build_configurations/compiler_options.cmake.orig	2020-01-01 21:24:49.736077000 +0100
+++ cmake/build_configurations/compiler_options.cmake	2020-01-01 21:25:22.307418000 +0100
@@ -32,7 +32,7 @@ IF(UNIX)  
 
   # Default GCC flags
   IF(CMAKE_COMPILER_IS_GNUCC)
-    SET(COMMON_C_FLAGS               "-g -fabi-version=2 -fno-omit-frame-pointer -fno-strict-aliasing")
+    SET(COMMON_C_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
       SET(COMMON_C_FLAGS             "-fno-inline ${COMMON_C_FLAGS}")
@@ -47,7 +47,7 @@ IF(UNIX)  
     IF(GXX_VERSION VERSION_EQUAL 6.0 OR GXX_VERSION VERSION_GREATER 6.0)
       SET(COMMON_CXX_FLAGS             "${COMMON_CXX_FLAGS} -std=gnu++03")
     ENDIF()
-    SET(COMMON_CXX_FLAGS               "-g -fabi-version=2 -fno-omit-frame-pointer -fno-strict-aliasing")
+    SET(COMMON_CXX_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
       SET(COMMON_CXX_FLAGS             "-fno-inline ${COMMON_CXX_FLAGS}")
