--- src/include/frmStatus.h.orig	Mon Jun 28 01:16:59 2004
+++ src/include/frmStatus.h	Mon Jun 28 01:21:48 2004
@@ -35,7 +35,9 @@
     void OnHelp(wxCommandEvent& ev);
     void OnClose(wxCommandEvent &event);
     void OnRefresh(wxCommandEvent &event);
+    void OnRefreshTimer(wxTimerEvent &event);
     void OnRateChange(wxCommandEvent &event);
+    void OnRateChangeSpin(wxSpinEvent &event);
     frmMain *mainForm;
     pgConn *connection;
     long backend_pid;
