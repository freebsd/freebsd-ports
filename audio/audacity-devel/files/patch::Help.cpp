--- Help.cpp.orig	Mon Sep 17 16:50:58 2001
+++ Help.cpp	Mon Sep 17 16:53:11 2001
@@ -61,7 +61,7 @@
 void InitHelp(wxWindow * parent)
 {
    if (!gHelp) {
-      wxString defaultLoc = wxGetCwd() + wxFILE_SEP_PATH + "audacity-help.htb";
+      wxString defaultLoc = AUDACITY_HELP_DIR + wxFILE_SEP_PATH + "audacity-help.htb";
 
       wxString helpFilePath =
           gPrefs->Read("/Help/HelpFilePath", defaultLoc);
