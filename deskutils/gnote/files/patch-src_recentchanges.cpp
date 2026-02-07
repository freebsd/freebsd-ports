--- src/recentchanges.cpp.orig	2023-09-25 18:30:51 UTC
+++ src/recentchanges.cpp
@@ -896,7 +896,6 @@ namespace gnote {
 
   Gtk::Popover *NoteRecentChanges::make_window_menu(Gtk::Button *button, std::vector<PopoverWidget> && items)
   {
-    std::sort(items.begin(), items.end());
     auto menu = Gio::Menu::create();
     if(items.size() > 0) {
       auto iter = items.begin();
