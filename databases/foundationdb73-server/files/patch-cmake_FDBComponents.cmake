--- cmake/FDBComponents.cmake.orig	2026-04-16 19:21:39 UTC
+++ cmake/FDBComponents.cmake
@@ -28,7 +28,7 @@ set(CMAKE_REQUIRED_INCLUDES ${OPENSSL_INCLUDE_DIR})
 # Statically link OpenSSL to FDB, see
 #    https://cmake.org/cmake/help/v3.24/module/FindOpenSSL.html
 # Without the flags, OpenSSL is dynamically linked.
-set(OPENSSL_USE_STATIC_LIBS TRUE)
+set(OPENSSL_USE_STATIC_LIBS FALSE)
 if (WIN32)
   set(OPENSSL_MSVC_STATIC_RT ON)
 endif()
@@ -199,6 +199,12 @@ endif()
 endif()
 
 ################################################################################
+# misc optional components
+################################################################################
+
+set(WITH_FLOWBENCH OFF)
+
+################################################################################
 # Coroutine implementation
 ################################################################################
 
@@ -242,6 +248,7 @@ function(print_components)
   message(STATUS "Build Documentation (make html):      ${WITH_DOCUMENTATION}")
   message(STATUS "Build Python sdist (make package):    ${WITH_PYTHON_BINDING}")
   message(STATUS "Configure CTest (depends on Python):  ${WITH_PYTHON}")
+  message(STATUS "Build with FlowBench:                 ${WITH_FLOWBENCH}")
   message(STATUS "Build with RocksDB:                   ${WITH_ROCKSDB_EXPERIMENTAL}")
   message(STATUS "Build with AWS SDK:                   ${WITH_AWS_BACKUP}")
   message(STATUS "=========================================")
