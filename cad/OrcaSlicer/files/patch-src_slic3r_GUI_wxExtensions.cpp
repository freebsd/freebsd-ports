--- src/slic3r/GUI/wxExtensions.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/wxExtensions.cpp
@@ -20,7 +20,7 @@
 #include "../Utils/WxFontUtils.hpp"
 #include "FilamentBitmapUtils.hpp"
 #include "../Utils/ColorSpaceConvert.hpp"
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 // msw_menuitem_bitmaps is used for MSW and OSX
 static std::map<int, std::string> msw_menuitem_bitmaps;
 #ifdef __WXMSW__
@@ -925,9 +925,9 @@ void ModeButton::focus_button(const bool focus)
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
