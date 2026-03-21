--- src/slic3r/GUI/GUI_ObjectList.cpp.orig	2025-03-01 00:00:00 UTC
+++ src/slic3r/GUI/GUI_ObjectList.cpp
@@ -130,7 +130,7 @@
 {
     wxGetApp().UpdateDVCDarkUI(this, true);

-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // Temporary fix for incorrect dark mode application regarding list item's text color.
     // See: https://github.com/SoftFever/OrcaSlicer/issues/2086
     this->SetForegroundColour(*wxBLACK);
