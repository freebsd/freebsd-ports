Create a cmake file for FreeBSD build.

--- cmake/bsd.cmake.orig	2019-06-10 03:23:23 UTC
+++ cmake/bsd.cmake
@@ -0,0 +1,20 @@
+# Default CMake Setup. Used for FreeBSD Builds.
+
+set(lib_base /usr/local/include)
+set(sdl_root ${lib_base}/SDL)
+
+include_directories("${sdl_root}")
+
+link_libraries(cannonball
+    SDL
+)
+
+# Linking
+link_directories(
+    "/usr/local/lib"
+)
+
+# Location for Cannonball to create save files
+# Used to auto-generate setup.hpp with various file paths
+set(xml_directory ./)
+set(sdl_flags "SDL_DOUBLEBUF | SDL_SWSURFACE")
