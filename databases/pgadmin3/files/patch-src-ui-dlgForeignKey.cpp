--- src/ui/dlgForeignKey.cpp.orig	Mon Jun 28 01:12:47 2004
+++ src/ui/dlgForeignKey.cpp	Mon Jun 28 01:13:06 2004
@@ -87,7 +87,7 @@
 }
 
 
-void dlgForeignKey::OnSelChangeCol(wxNotifyEvent &ev)
+void dlgForeignKey::OnSelChangeCol(wxListEvent &ev)
 {
     btnRemoveRef->Enable();
 }
