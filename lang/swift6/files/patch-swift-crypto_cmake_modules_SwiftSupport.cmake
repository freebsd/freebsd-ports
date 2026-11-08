--- swift-crypto/cmake/modules/SwiftSupport.cmake.orig	2026-10-10 18:48:34 UTC
+++ swift-crypto/cmake/modules/SwiftSupport.cmake
@@ -28,9 +28,9 @@
     else()
       set("${result_var_name}" "aarch64" PARENT_SCOPE)
     endif()
-  elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ppc64")
+  elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ppc64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "powerpc64")
     set("${result_var_name}" "powerpc64" PARENT_SCOPE)
-  elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ppc64le")
+  elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "ppc64le" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "powerpc64le")
     set("${result_var_name}" "powerpc64le" PARENT_SCOPE)
   elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "s390x")
     set("${result_var_name}" "s390x" PARENT_SCOPE)
