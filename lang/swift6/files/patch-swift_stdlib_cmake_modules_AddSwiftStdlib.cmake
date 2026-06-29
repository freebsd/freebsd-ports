--- swift/stdlib/cmake/modules/AddSwiftStdlib.cmake.orig	2024-06-06 04:26:30 UTC
+++ swift/stdlib/cmake/modules/AddSwiftStdlib.cmake
@@ -1209,6 +1209,10 @@ function(add_swift_target_library_single target name)
     set_target_properties("${target}"
       PROPERTIES
       INSTALL_RPATH "$ORIGIN")
+  elseif("${SWIFTLIB_SINGLE_SDK}" STREQUAL "FREEBSD")
+    set_target_properties("${target}"
+      PROPERTIES
+      INSTALL_RPATH "$ORIGIN")
   endif()
 
   set_target_properties("${target}" PROPERTIES BUILD_WITH_INSTALL_RPATH YES)
