--- cmake/build_configurations/compiler_options.cmake.orig	2016-08-25 11:52:06 UTC
+++ cmake/build_configurations/compiler_options.cmake
@@ -50,7 +50,7 @@ IF(UNIX)  
   IF(CMAKE_COMPILER_IS_GNUCC)
     SET(COMMON_C_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
     IF(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10.0)  # gcc-9 or older
-      SET(COMMON_C_FLAGS             "-fabi-version=2 ${COMMON_C_FLAGS}")
+      SET(COMMON_C_FLAGS             "${COMMON_C_FLAGS}")
     ENDIF()
     # Disable inline optimizations for valgrind testing to avoid false positives
     IF(WITH_VALGRIND)
@@ -77,7 +77,7 @@ IF(UNIX)  
   IF(CMAKE_COMPILER_IS_GNUCXX)
     SET(COMMON_CXX_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
     IF(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10.0)  # gcc-9 or older
-      SET(COMMON_CXX_FLAGS             "-fabi-version=2 ${COMMON_CXX_FLAGS}")
+      SET(COMMON_CXX_FLAGS             "${COMMON_CXX_FLAGS}")
     ENDIF()
     # GCC 6 has C++14 as default, set it explicitly to the old default.
     EXECUTE_PROCESS(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
