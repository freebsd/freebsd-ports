--- cmake/functions.cmake.orig	2026-05-02 02:29:25 UTC
+++ cmake/functions.cmake
@@ -200,7 +200,7 @@ function(wxfb_create_target_wxwidgets)
   endif()
   if(NOT wxWidgets_wxrc_EXECUTABLE)
     # Config-Mode does not search for wxrc, assume the environment is properly setup and search for it ourself
-    find_program(wxWidgets_wxrc_EXECUTABLE NAMES wxrc REQUIRED)
+    find_program(wxWidgets_wxrc_EXECUTABLE NAMES wxrc wxrc-3.2 REQUIRED)
     mark_as_advanced(wxWidgets_wxrc_EXECUTABLE)
   endif()
 
