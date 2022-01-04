--- cmake/FDBComponents.cmake.orig	2021-12-07 03:03:34 UTC
+++ cmake/FDBComponents.cmake
@@ -24,7 +24,7 @@ set(DISABLE_TLS OFF CACHE BOOL "Don't try to find Open
 if(DISABLE_TLS)
   set(WITH_TLS OFF)
 else()
-  set(OPENSSL_USE_STATIC_LIBS TRUE)
+  set(OPENSSL_USE_STATIC_LIBS FALSE)
   find_package(OpenSSL)
   if(OPENSSL_FOUND)
     set(CMAKE_REQUIRED_INCLUDES ${OPENSSL_INCLUDE_DIR})
@@ -203,6 +203,13 @@ else()
 endif()
 
 ################################################################################
+# misc optional components
+################################################################################
+
+set(WITH_CONTRIB ON)
+set(WITH_FLOWBENCH OFF)
+
+################################################################################
 # Coroutine implementation
 ################################################################################
 
@@ -236,6 +243,8 @@ function(print_components)
   message(STATUS "Build Documentation (make html):      ${WITH_DOCUMENTATION}")
   message(STATUS "Build Python sdist (make package):    ${WITH_PYTHON_BINDING}")
   message(STATUS "Configure CTest (depends on Python):  ${WITH_PYTHON}")
+  message(STATUS "Build contrib:                        ${WITH_CONTRIB}")
+  message(STATUS "Build with FlowBench:                 ${WITH_FLOWBENCH}")
   message(STATUS "Build with RocksDB:                   ${WITH_ROCKSDB_EXPERIMENTAL}")
   message(STATUS "=========================================")
 endfunction()
