--- src/include/frmQuery.h.orig	Mon Aug  4 04:39:32 2003
+++ src/include/frmQuery.h	Mon Jun 28 00:41:25 2004
@@ -48,7 +48,7 @@
     void OnSave(wxCommandEvent& event);
     void OnSaveAs(wxCommandEvent& event);
     void OnExport(wxCommandEvent& event);
-    void OnChange(wxNotifyEvent& event);
+    void OnChange(wxStyledTextEvent& event);
     void OnExit(wxCommandEvent& event);
     void OnRecent(wxCommandEvent& event);
     void OnCut(wxCommandEvent& event);
