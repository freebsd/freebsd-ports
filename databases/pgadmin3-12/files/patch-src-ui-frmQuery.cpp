--- src/ui/frmQuery.cpp.orig	Mon Sep  8 17:36:08 2003
+++ src/ui/frmQuery.cpp	Mon Jun 28 00:41:25 2004
@@ -587,7 +587,7 @@
 }
 
 
-void frmQuery::OnChange(wxNotifyEvent& event)
+void frmQuery::OnChange(wxStyledTextEvent& event)
 {
     if (!changed)
     {
