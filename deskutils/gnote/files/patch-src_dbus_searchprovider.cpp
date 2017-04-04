--- src/dbus/searchprovider.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/dbus/searchprovider.cpp
@@ -228,7 +228,7 @@ Glib::VariantContainerBase SearchProvide
 
 gchar *SearchProvider::get_icon()
 {
-  if(m_note_icon == 0) {
+  if(!m_note_icon) {
     Gtk::IconInfo info = gnote::IconManager::obj().lookup_icon(gnote::IconManager::NOTE, 48);
     m_note_icon = Gio::Icon::create(info.get_filename());
   }
