--- Modules/Platform/FreeBSD.cmake.orig	2024-11-06 13:41:37 UTC
+++ Modules/Platform/FreeBSD.cmake
@@ -26,6 +26,11 @@ endforeach()
   set(CMAKE_${type}_LINK_DYNAMIC_C_FLAGS "-Wl,-Bdynamic")
 endforeach()
 
+# Prefer python3 (installed by the python3 metaport) over the
+# highest-versioned Python3 interpreter, when asked for a non-exact
+# Python3 version.
+set(Python3_FIND_UNVERSIONED_NAMES FIRST)
+
 
 # Features for LINK_GROUP generator expression
 ## RESCAN: request the linker to rescan static libraries until there is
