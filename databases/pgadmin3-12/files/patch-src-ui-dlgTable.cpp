--- src/ui/dlgTable.cpp.orig	Tue Oct  7 17:20:42 2003
+++ src/ui/dlgTable.cpp	Mon Jun 28 00:41:25 2004
@@ -491,7 +491,7 @@
 }
 
 
-void dlgTable::OnChange(wxNotifyEvent &ev)
+void dlgTable::OnChange(wxCommandEvent &ev)
 {
     if (table)
     {
@@ -520,7 +520,7 @@
 }
 
 
-void dlgTable::OnAddTable(wxNotifyEvent &ev)
+void dlgTable::OnAddTable(wxCommandEvent &ev)
 {
     int sel=cbTables->GetSelection();
     if (sel >= 0)
@@ -552,7 +552,7 @@
 }
 
 
-void dlgTable::OnRemoveTable(wxNotifyEvent &ev)
+void dlgTable::OnRemoveTable(wxCommandEvent &ev)
 {
     int sel=lbTables->GetSelection();
     if (sel >= 0)
@@ -576,13 +576,13 @@
 }
 
 
-void dlgTable::OnSelChangeTable(wxListEvent &ev)
+void dlgTable::OnSelChangeTable(wxCommandEvent &ev)
 {
     btnRemoveTable->Enable();
 }
 
 
-void dlgTable::OnChangeCol(wxNotifyEvent &ev)
+void dlgTable::OnChangeCol(wxCommandEvent &ev)
 {
     long pos=GetListSelected(lstColumns);
     pgColumn *column=(pgColumn*) StrToLong(GetListText(lstColumns, pos, 4));
@@ -596,30 +596,30 @@
         lstColumns->SetItem(pos, 1, col.GetDefinition());
         lstColumns->SetItem(pos, 3, col.GetSql());
     }
-    wxNotifyEvent event;
+    wxCommandEvent event;
     OnChange(event);
 }
 
 
-void dlgTable::OnAddCol(wxNotifyEvent &ev)
+void dlgTable::OnAddCol(wxCommandEvent &ev)
 {
     dlgColumn col(mainForm, NULL, table);
     col.CenterOnParent();
     col.SetConnection(connection);
     if (col.Go(true) >= 0)
         AppendListItem(lstColumns, col.GetName(), col.GetDefinition(), PGICON_COLUMN);
-    wxNotifyEvent event;
+    wxCommandEvent event;
     OnChange(event);
 }
 
 
-void dlgTable::OnRemoveCol(wxNotifyEvent &ev)
+void dlgTable::OnRemoveCol(wxCommandEvent &ev)
 {
     lstColumns->DeleteItem(GetListSelected(lstColumns));
 
     btnRemoveCol->Disable();
 
-    wxNotifyEvent event;
+    wxCommandEvent event;
     OnChange(event);
 }
 
@@ -634,7 +634,7 @@
 }
 
 
-void dlgTable::OnAddConstr(wxNotifyEvent &ev)
+void dlgTable::OnAddConstr(wxCommandEvent &ev)
 {
     int sel=cbConstrType->GetSelection();
     if (hasPK)
@@ -687,12 +687,12 @@
             break;
         }
     }
-    wxNotifyEvent event;
+    wxCommandEvent event;
     OnChange(event);
 }
 
 
-void dlgTable::OnRemoveConstr(wxNotifyEvent &ev)
+void dlgTable::OnRemoveConstr(wxCommandEvent &ev)
 {
     int pos=GetListSelected(lstConstraints);
     if (pos < 0)
@@ -711,7 +711,7 @@
     
     lstConstraints->DeleteItem(pos);
     btnRemoveConstr->Disable();
-    wxNotifyEvent event;
+    wxCommandEvent event;
     OnChange(event);
 }
 
