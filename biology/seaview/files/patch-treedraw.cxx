--- treedraw.cxx.orig	2018-08-25 03:51:23 UTC
+++ treedraw.cxx
@@ -322,7 +322,7 @@ Fl_Window *treedraw(char *trees, SEA_VIEW *view, const
     {"Save all trees", 0, file_callback, NULL, 0},
     {"Save patristic distances", 0, patristic_callback, NULL, FL_MENU_DIVIDER},
     {"Print", FL_COMMAND | 'p', file_callback, NULL, 0},
-    {"Save as "PDF_OR_PS"", 0, file_callback, NULL, 0},
+    {"Save as " PDF_OR_PS "", 0, file_callback, NULL, 0},
     {"A4", 0, file_callback, NULL, FL_MENU_RADIO | 0},
     {"Letter", 0, file_callback, NULL, FL_MENU_RADIO | 0},
     {"Landscape", 0, file_callback, NULL, FL_MENU_TOGGLE},
