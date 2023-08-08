--- cmake/FDBComponents.cmake.orig	2022-09-19 11:42:41 UTC
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
@@ -198,6 +198,13 @@ endif()
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
 
@@ -242,6 +249,8 @@ function(print_components)
   message(STATUS "Build Documentation (make html):      ${WITH_DOCUMENTATION}")
   message(STATUS "Build Python sdist (make package):    ${WITH_PYTHON_BINDING}")
   message(STATUS "Configure CTest (depends on Python):  ${WITH_PYTHON}")
+  message(STATUS "Build contrib:                        ${WITH_CONTRIB}")
+  message(STATUS "Build with FlowBench:                 ${WITH_FLOWBENCH}")
   message(STATUS "Build with RocksDB:                   ${WITH_ROCKSDB_EXPERIMENTAL}")
   message(STATUS "Build with AWS SDK:                   ${WITH_AWS_BACKUP}")
   message(STATUS "=========================================")
