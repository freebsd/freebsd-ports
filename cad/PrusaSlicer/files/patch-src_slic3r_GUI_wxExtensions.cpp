--- src/slic3r/GUI/wxExtensions.cpp.orig	2023-07-25 13:02:00 UTC
+++ src/slic3r/GUI/wxExtensions.cpp
@@ -22,7 +22,7 @@
 
 #include "libslic3r/Color.hpp"
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 // msw_menuitem_bitmaps is used for MSW and OSX
 static std::map<int, std::string> msw_menuitem_bitmaps;
 void sys_color_changed_menu(wxMenu* menu)
@@ -92,7 +92,7 @@ wxMenuItem* append_menu_item(wxMenu* menu, int id, con
 
     wxBitmapBundle* bmp = icon.empty() ? nullptr : get_bmp_bundle(icon);
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
     if (bmp && bmp->IsOk())
         msw_menuitem_bitmaps[id] = icon;
 #endif /* no __linux__ */
@@ -110,7 +110,7 @@ wxMenuItem* append_submenu(wxMenu* menu, wxMenu* sub_m
     if (!icon.empty()) {
         item->SetBitmap(*get_bmp_bundle(icon));
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
         msw_menuitem_bitmaps[id] = icon;
 #endif // no __linux__
     }
@@ -671,9 +671,9 @@ void ModeButton::focus_button(const bool focus)
     GetParent()->Refresh(); // force redraw a background of the selected mode button
 #else
     SetForegroundColour(wxSystemSettings::GetColour(focus ? wxSYS_COLOUR_BTNTEXT : 
-#if defined (__linux__) && defined (__WXGTK3__)
+#if (defined (__linux__) || defined(__FreeBSD__)) && defined (__WXGTK3__)
         wxSYS_COLOUR_GRAYTEXT
-#elif defined (__linux__) && defined (__WXGTK2__)
+#elif (defined (__linux__) || defined(__FreeBSD__)) && defined (__WXGTK2__)
         wxSYS_COLOUR_BTNTEXT
 #else 
         wxSYS_COLOUR_BTNSHADOW
