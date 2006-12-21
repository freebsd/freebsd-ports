--- sdk/editormanager.h.orig	Wed Dec 20 23:49:21 2006
+++ sdk/editormanager.h	Wed Dec 20 23:50:21 2006
@@ -126,7 +126,7 @@
 
         /** Builds Opened Files tree in the Projects tab
           */
-        wxTreeCtrl *EditorManager::GetTree();
+        wxTreeCtrl *GetTree();
         wxTreeItemId FindTreeFile(const wxString& filename);
         wxString GetTreeItemFilename(wxTreeItemId item);
         void BuildOpenedFilesTree(wxWindow* parent);
