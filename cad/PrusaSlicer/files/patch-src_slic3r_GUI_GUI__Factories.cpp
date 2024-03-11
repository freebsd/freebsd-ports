--- src/slic3r/GUI/GUI_Factories.cpp.orig	2024-02-29 13:03:32 UTC
+++ src/slic3r/GUI/GUI_Factories.cpp
@@ -1466,7 +1466,7 @@ void MenuFactory::sys_color_changed(wxMenuBar* menubar
     for (size_t id = 0; id < menubar->GetMenuCount(); id++) {
         wxMenu* menu = menubar->GetMenu(id);
         sys_color_changed_menu(menu);
-#ifndef __linux__
+#if !(defined(__linux__) || defined (__FreeBSD__))
         menu->SetupBitmaps();
 #ifdef _WIN32 
         // but under MSW we have to update item's bachground color
