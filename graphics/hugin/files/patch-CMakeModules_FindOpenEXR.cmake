--- CMakeModules/FindOpenEXR.cmake.orig	2021-09-07 14:16:50 UTC
+++ CMakeModules/FindOpenEXR.cmake
@@ -35,7 +35,7 @@ ENDIF (NOT WIN32 OR MINGW)
   include(FindLibraryWithDebug)
   find_library_with_debug(OPENEXR_HALF_LIBRARY 
     WIN32_DEBUG_POSTFIX d
-    NAMES Half-2_5 Half-2_4 Half-2_3 Half
+    NAMES Imath
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
@@ -45,7 +45,7 @@ ENDIF (NOT WIN32 OR MINGW)
 
   find_library_with_debug(OPENEXR_IEX_LIBRARY
     WIN32_DEBUG_POSTFIX d
-    NAMES Iex-2_5 Iex-2_4 Iex-2_3 Iex-2_2 Iex
+    NAMES Iex
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
@@ -55,7 +55,7 @@ ENDIF (NOT WIN32 OR MINGW)
 
   find_library_with_debug(OPENEXR_ILMTHREAD_LIBRARY 
     WIN32_DEBUG_POSTFIX d
-    NAMES IlmThread-2_5 IlmThread-2_4 IlmThread-2_3 IlmThread-2_2 IlmThread
+    NAMES IlmThread
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
@@ -65,7 +65,7 @@ ENDIF (NOT WIN32 OR MINGW)
   
   find_library_with_debug(OPENEXR_IMATH_LIBRARY 
     WIN32_DEBUG_POSTFIX d
-    NAMES Imath-2_5 Imath-2_4 Imath-2_3 Imath-2_2 Imath
+    NAMES Imath
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
@@ -76,7 +76,7 @@ ENDIF (NOT WIN32 OR MINGW)
   
   find_library_with_debug(OPENEXR_ILMIMF_LIBRARY 
     WIN32_DEBUG_POSTFIX d
-    NAMES IlmImf-2_5 IlmImf-2_4 IlmImf-2_3 IlmImf-2_2 IlmImf 
+    NAMES OpenEXR
     PATHS
       ${_OPENEXRLinkDir}
       ${SYSTEM_LIB_DIRS}
