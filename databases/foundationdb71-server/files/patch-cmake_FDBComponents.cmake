--- cmake/FDBComponents.cmake.orig	2025-01-15 16:19:53 UTC
+++ cmake/FDBComponents.cmake
@@ -24,7 +24,7 @@ else()
 if(DISABLE_TLS)
   set(WITH_TLS OFF)
 else()
-  set(OPENSSL_USE_STATIC_LIBS TRUE)
+  set(OPENSSL_USE_STATIC_LIBS FALSE)
   if(WIN32)
     set(OPENSSL_MSVC_STATIC_RT ON)
   endif()
@@ -204,6 +204,12 @@ endif()
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
 
@@ -248,6 +254,7 @@ function(print_components)
   message(STATUS "Build Documentation (make html):      ${WITH_DOCUMENTATION}")
   message(STATUS "Build Python sdist (make package):    ${WITH_PYTHON_BINDING}")
   message(STATUS "Configure CTest (depends on Python):  ${WITH_PYTHON}")
+  message(STATUS "Build with FlowBench:                 ${WITH_FLOWBENCH}")
   message(STATUS "Build with RocksDB:                   ${WITH_ROCKSDB_EXPERIMENTAL}")
   message(STATUS "Build with AWS SDK:                   ${WITH_AWS_BACKUP}")
   message(STATUS "=========================================")
