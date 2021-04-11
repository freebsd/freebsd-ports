--- build_files/Modules/FindOpenEXR.cmake.orig	2017-05-10 19:14:06 UTC
+++ build_files/Modules/FindOpenEXR.cmake
@@ -39,18 +39,16 @@ if (NOT OPENEXR_VERSION)
 endif()
 if (${OPENEXR_VERSION} VERSION_LESS "2.1")
   SET(_openexr_FIND_COMPONENTS
-    Half
     Iex
-    IlmImf
+    OpenEXR
     IlmThread
     Imath
   )
 else ()
   string(REGEX REPLACE "([0-9]+)[.]([0-9]+).*" "\\1_\\2" _openexr_libs_ver ${OPENEXR_VERSION})
   SET(_openexr_FIND_COMPONENTS
-    Half
+    OpenEXR-${_openexr_libs_ver}
     Iex-${_openexr_libs_ver}
-    IlmImf-${_openexr_libs_ver}
     IlmThread-${_openexr_libs_ver}
     Imath-${_openexr_libs_ver}
   )
