--- src/include/dlgForeignKey.h.orig	Mon Jun 28 01:12:17 2004
+++ src/include/dlgForeignKey.h	Mon Jun 28 01:12:29 2004
@@ -35,7 +35,7 @@
 
     void OnChange(wxNotifyEvent &ev);
     void OnCheckDeferrable(wxNotifyEvent &ev);
-    void OnSelChangeCol(wxNotifyEvent &ev);
+    void OnSelChangeCol(wxListEvent &ev);
     void OnSelChangeRef(wxNotifyEvent &ev);
     void OnSelChangeRefCol(wxNotifyEvent &ev);
     void OnAddRef(wxNotifyEvent &ev);
