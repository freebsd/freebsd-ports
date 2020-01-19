--- Modules/FindFLEX.cmake.orig	2020-01-19 09:02:30 UTC
+++ Modules/FindFLEX.cmake
@@ -103,10 +103,15 @@ find_program(FLEX_EXECUTABLE NAMES flex win_flex DOC "
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
 
