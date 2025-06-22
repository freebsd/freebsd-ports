--- swift/tools/SourceKit/cmake/modules/AddSwiftSourceKit.cmake.orig	2024-06-06 04:26:30 UTC
+++ swift/tools/SourceKit/cmake/modules/AddSwiftSourceKit.cmake
@@ -115,7 +115,7 @@ function(add_sourcekit_swift_runtime_link_flags target
                    LINK_FLAGS " -lobjc ")
 
     endif() # HAS_SWIFT_MODULES AND ASKD_BOOTSTRAPPING_MODE
-  elseif(SWIFT_HOST_VARIANT_SDK MATCHES "LINUX|ANDROID|OPENBSD" AND HAS_SWIFT_MODULES AND ASKD_BOOTSTRAPPING_MODE)
+  elseif(SWIFT_HOST_VARIANT_SDK MATCHES "LINUX|ANDROID|FREEBSD|OPENBSD" AND HAS_SWIFT_MODULES AND ASKD_BOOTSTRAPPING_MODE)
     set(swiftrt "swiftImageRegistrationObject${SWIFT_SDK_${SWIFT_HOST_VARIANT_SDK}_OBJECT_FORMAT}-${SWIFT_SDK_${SWIFT_HOST_VARIANT_SDK}_LIB_SUBDIR}-${SWIFT_HOST_VARIANT_ARCH}")
     if(ASKD_BOOTSTRAPPING_MODE MATCHES "HOSTTOOLS|CROSSCOMPILE")
       # At build time and run time, link against the swift libraries in the
