--- CMakeModules/FindOpenEXR.cmake.orig	2019-12-07 08:35:27 UTC
+++ CMakeModules/FindOpenEXR.cmake
@@ -35,7 +35,7 @@ ENDIF (NOT WIN32 OR MINGW)
   include(FindLibraryWithDebug)
   find_library_with_debug(OPENEXR_HALF_LIBRARY 
     WIN32_DEBUG_POSTFIX d
-    NAMES Half-2_3 Half
+    NAMES Imath
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
@@ -45,7 +45,7 @@ ENDIF (NOT WIN32 OR MINGW)
 
   find_library_with_debug(OPENEXR_IEX_LIBRARY
     WIN32_DEBUG_POSTFIX d
-    NAMES Iex-2_3 Iex-2_2 Iex
+    NAMES Iex
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
@@ -76,7 +76,7 @@ ENDIF (NOT WIN32 OR MINGW)
   
   find_library_with_debug(OPENEXR_ILMIMF_LIBRARY 
     WIN32_DEBUG_POSTFIX d
-    NAMES IlmImf-2_3 IlmImf-2_2 IlmImf 
+    NAMES OpenEXR
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
