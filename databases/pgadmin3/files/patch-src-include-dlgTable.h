--- src/include/dlgTable.h.orig	Mon Aug 11 17:36:55 2003
+++ src/include/dlgTable.h	Mon Jun 28 00:41:25 2004
@@ -32,19 +32,19 @@
     pgSchema *schema;
     pgTable *table;
 
-    void OnChange(wxNotifyEvent &ev);
+    void OnChange(wxCommandEvent &ev);
 
-    void OnAddTable(wxNotifyEvent &ev);
-    void OnRemoveTable(wxNotifyEvent &ev);
-    void OnSelChangeTable(wxListEvent &ev);
+    void OnAddTable(wxCommandEvent &ev);
+    void OnRemoveTable(wxCommandEvent &ev);
+    void OnSelChangeTable(wxCommandEvent &ev);
 
-    void OnAddCol(wxNotifyEvent &ev);
-    void OnChangeCol(wxNotifyEvent &ev);
-    void OnRemoveCol(wxNotifyEvent &ev);
+    void OnAddCol(wxCommandEvent &ev);
+    void OnChangeCol(wxCommandEvent &ev);
+    void OnRemoveCol(wxCommandEvent &ev);
     void OnSelChangeCol(wxListEvent &ev);
 
-    void OnAddConstr(wxNotifyEvent &ev);
-    void OnRemoveConstr(wxNotifyEvent &ev);
+    void OnAddConstr(wxCommandEvent &ev);
+    void OnRemoveConstr(wxCommandEvent &ev);
     void OnSelChangeConstr(wxListEvent &ev);
 
     void FillConstraint();
