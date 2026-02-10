--- src/chmhtmlwindow.cpp.orig	2026-02-01 10:31:54 UTC
+++ src/chmhtmlwindow.cpp
@@ -42,7 +42,7 @@ class CHMDropTarget : public wxFileDropTarget { (publi
 
     bool OnDropFiles(wxCoord /* x */, wxCoord /* y */, const wxArrayString& filenames) override
     {
-        if (filenames.size() == 1 && filenames[0].Lower().ends_with(".chm")) {
+        if (filenames.size() == 1 && filenames[0].Lower().EndsWith(".chm")) {
             _frame->LoadCHM(filenames[0]);
             return true;
         }
