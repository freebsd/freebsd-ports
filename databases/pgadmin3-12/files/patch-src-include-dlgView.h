--- src/include/dlgView.h.orig	Mon Jun 28 00:53:54 2004
+++ src/include/dlgView.h	Mon Jun 28 00:54:12 2004
@@ -34,6 +34,7 @@
     wxString oldDefinition;
 
     void OnChange(wxNotifyEvent &ev);
+    void OnChangeStyled(wxStyledTextEvent &ev);
 
     ctlSQLBox *sqlBox;
 
