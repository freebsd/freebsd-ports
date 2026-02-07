--- swift/cmake/modules/SwiftConfigureSDK.cmake.orig	2024-06-06 04:26:30 UTC
+++ swift/cmake/modules/SwiftConfigureSDK.cmake
@@ -378,7 +378,7 @@ macro(configure_sdk_unix name architectures)
           message(FATAL_ERROR "unknown arch for ${prefix}: ${arch}")
         endif()
       elseif("${prefix}" STREQUAL "FREEBSD")
-        if(NOT arch MATCHES "(arm64|x86_64)")
+        if(NOT arch MATCHES "(aarch64|x86_64)")
           message(FATAL_ERROR "unsupported arch for FreeBSD: ${arch}")
         endif()
 
