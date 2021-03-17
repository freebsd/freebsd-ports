Adds support for building in BSD.

Will be removed once upstream makes a release with
https://github.com/djyt/cannonball/commit/a9c71cbf229b9f808ae172a09d12a773fc869209

--- cmake/linux.cmake.orig	2021-03-16 11:22:26 UTC
+++ cmake/linux.cmake
@@ -0,0 +1,12 @@
+# -----------------------------------------------------------------------------
+# CannonBall BSD Setup
+# -----------------------------------------------------------------------------
+
+# Use OpenGL for rendering.
+find_package(OpenGL REQUIRED)
+
+# Platform Specific Libraries
+set(platform_link_libs
+    ${OPENGL_LIBRARIES}
+)
+
