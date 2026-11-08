--- swift/cmake/modules/SwiftConfigureSDK.cmake.orig	2026-10-10 18:48:34 UTC
+++ swift/cmake/modules/SwiftConfigureSDK.cmake
@@ -426,7 +426,7 @@
           message(FATAL_ERROR "unknown arch for ${prefix}: ${arch}")
         endif()
       elseif("${prefix}" STREQUAL "FREEBSD")
-        if(NOT arch MATCHES "(aarch64|x86_64)")
+        if(NOT arch MATCHES "(aarch64|powerpc64le|x86_64)")
           message(FATAL_ERROR "unsupported arch for FreeBSD: ${arch}")
         endif()
 
