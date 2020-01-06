--- src/tkscid.cpp.orig	2019-12-02 11:36:00 UTC
+++ src/tkscid.cpp
@@ -4510,7 +4510,7 @@ sc_game_tags_set (ClientData, Tcl_Interp * ti, int arg
                     int largc;
                     const char ** largv;
                     if (Tcl_SplitList (ti, value, &largc,
-                                       (CONST84 char ***) &largv) != TCL_OK) {
+                                       (const char ***) &largv) != TCL_OK) {
                         // Error from Tcl_SplitList!
                         return errorResult (ti, "Error parsing extra tags.");
                     }
@@ -9330,7 +9330,7 @@ sc_search_header (ClientData, Tcl_Interp * ti, scidBas
 
         case OPT_PGN:
             if (Tcl_SplitList (ti, (char *)value, &pgnTextCount,
-                               (CONST84 char ***) &sPgnText) != TCL_OK) {
+                               (const char ***) &sPgnText) != TCL_OK) {
                 delete[] wTitles;
                 delete[] bTitles;
                 return TCL_ERROR;
