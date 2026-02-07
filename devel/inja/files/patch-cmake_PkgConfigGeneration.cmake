--- cmake/PkgConfigGeneration.cmake.orig	2025-09-18 10:40:00 UTC
+++ cmake/PkgConfigGeneration.cmake
@@ -0,0 +1,18 @@
+#.rst:
+# PkgConfigGeneration
+# -------------------
+#
+# Generate the pkg-config file for libdispatch.
+#
+# The script generates a pkg-config file on non-Apple UNIX-like systems.
+#
+
+# Check if the system is UNIX-based and not Apple
+if(UNIX)
+  # Configure the pkg-config file from the template
+  configure_file("${PROJECT_SOURCE_DIR}/cmake/inja.pc.in"
+                 "${PROJECT_BINARY_DIR}/inja.pc" @ONLY)
+
+  # Install the generated pkg-config file to the appropriate directory
+  install(FILES "${PROJECT_BINARY_DIR}/inja.pc" DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig")
+endif()
