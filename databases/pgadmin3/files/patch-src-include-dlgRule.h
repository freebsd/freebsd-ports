--- src/include/dlgRule.h.orig	Mon Jun 28 00:58:04 2004
+++ src/include/dlgRule.h	Mon Jun 28 00:58:20 2004
@@ -34,6 +34,7 @@
     wxString oldDefinition;
 
     void OnChange(wxNotifyEvent &ev);
+    void OnChangeStyled(wxStyledTextEvent &ev);
 
     bool didChange();
 
