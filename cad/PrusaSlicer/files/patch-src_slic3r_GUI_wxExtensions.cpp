--- src/slic3r/GUI/wxExtensions.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/wxExtensions.cpp
@@ -28,7 +28,7 @@
 
 #include "libslic3r/Color.hpp"
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 // msw_menuitem_bitmaps is used for MSW and OSX
 static std::map<int, std::string> msw_menuitem_bitmaps;
 void sys_color_changed_menu(wxMenu* menu)
@@ -137,7 +137,7 @@ wxMenuItem* append_menu_item(wxMenu* menu, int id, con
 
     wxBitmapBundle* bmp = icon.empty() ? nullptr : get_bmp_bundle(icon);
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
     if (bmp && bmp->IsOk())
         msw_menuitem_bitmaps[id] = icon;
 #endif /* no __linux__ */
@@ -155,7 +155,7 @@ wxMenuItem* append_submenu(wxMenu* menu, wxMenu* sub_m
     if (!icon.empty()) {
         item->SetBitmap(*get_bmp_bundle(icon));
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
         msw_menuitem_bitmaps[id] = icon;
 #endif // no __linux__
     }
@@ -218,7 +218,7 @@ void set_menu_item_bitmap(wxMenuItem* item, const std:
 void set_menu_item_bitmap(wxMenuItem* item, const std::string& icon_name)
 {
     item->SetBitmap(*get_bmp_bundle(icon_name));
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
     const auto it = msw_menuitem_bitmaps.find(item->GetId());
     if (it != msw_menuitem_bitmaps.end() && it->second != icon_name)
         it->second = icon_name;
