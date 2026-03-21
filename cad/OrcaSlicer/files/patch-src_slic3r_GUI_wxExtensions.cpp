--- src/slic3r/GUI/wxExtensions.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/wxExtensions.cpp
@@ -18,7 +18,7 @@
 #include "Widgets/StaticBox.hpp"
 #include "Widgets/Label.hpp"
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 // msw_menuitem_bitmaps is used for MSW and OSX
 static std::map<int, std::string> msw_menuitem_bitmaps;
 #ifdef __WXMSW__
@@ -774,9 +774,9 @@ void ModeButton::focus_button(const bool focus)
     GetParent()->Refresh(); // force redraw a background of the selected mode button
 #else
     SetForegroundColour(wxSystemSettings::GetColour(focus ? wxSYS_COLOUR_BTNTEXT : 
-#if defined (__linux__) && defined (__WXGTK3__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__WXGTK3__)
         wxSYS_COLOUR_GRAYTEXT
-#elif defined (__linux__) && defined (__WXGTK2__)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(__WXGTK2__)
         wxSYS_COLOUR_BTNTEXT
 #else 
         wxSYS_COLOUR_BTNSHADOW
