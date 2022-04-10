--- Modules/Platform/FreeBSD.cmake.orig	2022-04-10 15:22:59 UTC
+++ Modules/Platform/FreeBSD.cmake
@@ -26,4 +26,9 @@ foreach(type SHARED_LIBRARY SHARED_MODULE EXE)
   set(CMAKE_${type}_LINK_DYNAMIC_C_FLAGS "-Wl,-Bdynamic")
 endforeach()
 
+# Prefer python3 (installed by the python3 metaport) over the
+# highest-versioned Python3 interpreter, when asked for a non-exact
+# Python3 version.
+set(Python3_FIND_UNVERSIONED_NAMES FIRST)
+
 include(Platform/UnixPaths)
