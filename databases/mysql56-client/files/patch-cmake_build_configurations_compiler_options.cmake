--- cmake/build_configurations/compiler_options.cmake.orig	2016-03-03 16:35:33.000000000 +0100
+++ cmake/build_configurations/compiler_options.cmake	2016-04-19 17:30:13.345558666 +0200
@@ -25,7 +25,7 @@ IF(UNIX)  
 
   # Default GCC flags
   IF(CMAKE_COMPILER_IS_GNUCC)
-    SET(COMMON_C_FLAGS               "-g -fabi-version=2 -fno-omit-frame-pointer -fno-strict-aliasing")
+    SET(COMMON_C_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
       SET(COMMON_C_FLAGS             "-fno-inline ${COMMON_C_FLAGS}")
@@ -34,7 +34,7 @@ IF(UNIX)  
     SET(CMAKE_C_FLAGS_RELWITHDEBINFO "-O3 ${COMMON_C_FLAGS}")
   ENDIF()
   IF(CMAKE_COMPILER_IS_GNUCXX)
-    SET(COMMON_CXX_FLAGS               "-g -fabi-version=2 -fno-omit-frame-pointer -fno-strict-aliasing")
+    SET(COMMON_CXX_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
       SET(COMMON_CXX_FLAGS             "-fno-inline ${COMMON_CXX_FLAGS}")
