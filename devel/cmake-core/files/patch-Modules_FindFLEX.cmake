--- Modules/FindFLEX.cmake.orig	2026-08-23 04:05:48 UTC
+++ Modules/FindFLEX.cmake
@@ -273,10 +273,15 @@ find_library(FL_LIBRARY NAMES fl
 mark_as_advanced(FLEX_EXECUTABLE)
 
 find_library(FL_LIBRARY NAMES fl
-  DOC "Path to the fl library")
+  DOC "Path to the fl library"
+  PATHS %%LOCALBASE%%/lib
+  )
 
 find_path(FLEX_INCLUDE_DIR FlexLexer.h
-  DOC "Path to the flex headers")
+  DOC "Path to the flex headers"
+  PATHS %%LOCALBASE%%/include
+  PATH_SUFFIXES flex
+  )
 
 mark_as_advanced(FL_LIBRARY FLEX_INCLUDE_DIR)
 
