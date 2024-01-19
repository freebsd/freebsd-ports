Hunk 1: Set FREETYPE_INCLUDE_DIR_ft2build and FREETYPE_INCLUDE_DIR_freetype2
if the freetype config is found for backwards compatibility.
Regressed by [1].

Hunk 2: Fix some weirdness that happens in games/arx-libertatis where the
the REMOVE_DUPLICATES directive of the CMake list() command removes the
OpenAL library from the link libraries list because it was the next
library in the list. It is unlikely that one would have both the debug
and release versions of FreeType installed on FreeBSD as we don't
currently have the infrastructure to simultaneously support a suffixed
and non-suffixed freetype library. Honestly, I don't even know what this
contruct is supposed to represent. The CMake set() command [3] doesn't
specify allowance of metadata constructs like "optimized" and "debug"
before variable assignment and further confuses ports like
graphics/ogre3d that try to link against nonsense libraries like
-loptimized and -ldebug.
Regessed by [2].

[1] https://gitlab.kitware.com/cmake/cmake/-/commit/d83d925045484c882527477b01596073f45d3faa
[2] https://gitlab.kitware.com/cmake/cmake/-/commit/1cfc708eea11df5fd8c438f517e24940b6cc1917
[3] https://cmake.org/cmake/help/latest/command/set.html

--- Modules/FindFreetype.cmake.orig	2023-12-14 15:47:27 UTC
+++ Modules/FindFreetype.cmake
@@ -106,6 +106,8 @@ if (freetype_FOUND)
       INTERFACE_LINK_LIBRARIES freetype)
   endif ()
   get_property(FREETYPE_INCLUDE_DIRS TARGET freetype PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
+  get_property(FREETYPE_INCLUDE_DIR_ft2build TARGET freetype PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
+  get_property(FREETYPE_INCLUDE_DIR_freetype2 TARGET freetype PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
   get_property(FREETYPE_LIBRARIES TARGET freetype PROPERTY INTERFACE_LINK_LIBRARIES)
   get_property(_Freetype_location TARGET freetype PROPERTY IMPORTED_IMPLIB)
   if (NOT _Freetype_location)
@@ -128,11 +130,7 @@ if (freetype_FOUND)
         get_property(_Freetype_location_release TARGET freetype PROPERTY LOCATION_RELWITHDEBINFO)
       endif ()
       get_property(_Freetype_location_debug TARGET freetype PROPERTY LOCATION_DEBUG)
-      if (_Freetype_location_release AND _Freetype_location_debug)
-        set(_Freetype_location
-          optimized "${_Freetype_location_release}"
-          debug "${_Freetype_location_debug}")
-      elseif (_Freetype_location_release)
+      if (_Freetype_location_release)
         set(_Freetype_location "${_Freetype_location_release}")
       elseif (_Freetype_location_debug)
         set(_Freetype_location "${_Freetype_location_debug}")
