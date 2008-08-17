--- gui.cpp.orig	2008-08-16 23:38:20.000000000 -0400
+++ gui.cpp	2008-08-16 23:38:29.000000000 -0400
@@ -631,6 +631,9 @@
 #endif
 }
 
+#ifndef wxHIDE_READONLY
+#define wxHIDE_READONLY 0
+#endif
 
 void MyFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
 {
