--- src/recentchanges.cpp.orig	2021-09-01 22:35:10 UTC
+++ src/recentchanges.cpp
@@ -842,7 +842,6 @@ namespace gnote {
 
   Gtk::PopoverMenu *NoteRecentChanges::make_window_menu(Gtk::Button *button, std::vector<PopoverWidget> && items)
   {
-    std::sort(items.begin(), items.end());
     Gtk::PopoverMenu *menu = manage(new Gtk::PopoverMenu);
     Gtk::Box *menu_box = manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
     utils::set_common_popover_widget_props(*menu_box);
