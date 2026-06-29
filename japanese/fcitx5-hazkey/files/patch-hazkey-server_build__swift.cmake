--- hazkey-server/build_swift.cmake.orig	2026-02-08 10:07:38 UTC
+++ hazkey-server/build_swift.cmake
@@ -2,6 +2,8 @@ set(SWIFT_COMMAND
     "${SWIFT_EXECUTABLE}"
     "build" "-c" "${SWIFT_BUILD_TYPE}"
     "--scratch-path=${CMAKE_CURRENT_BINARY_DIR}/swift-build"
+    "--skip-update"
+    "-Xlinker" "-lexecinfo"
 )
 
 if(HAZKEY_SERVER_ZENZAI_TRAIT)
