--- src/slic3r/GUI/GUI_ObjectList.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/GUI_ObjectList.cpp
@@ -135,7 +135,7 @@ ObjectList::ObjectList(wxWindow* parent) :
 {
     wxGetApp().UpdateDVCDarkUI(this, true);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // Temporary fix for incorrect dark mode application regarding list item's text color.
     // See: https://github.com/OrcaSlicer/OrcaSlicer/issues/2086
     this->SetForegroundColour(*wxBLACK);
