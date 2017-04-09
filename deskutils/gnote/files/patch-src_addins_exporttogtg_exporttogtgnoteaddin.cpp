--- src/addins/exporttogtg/exporttogtgnoteaddin.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/addins/exporttogtg/exporttogtgnoteaddin.cpp
@@ -79,10 +79,10 @@ void ExportToGTGNoteAddin::on_note_opene
 void ExportToGTGNoteAddin::export_button_clicked()
 {
   try {
-    if (s_gtg_interface == 0) {
+    if (!s_gtg_interface) {
       Glib::RefPtr<Gio::DBus::NodeInfo> node_info = Gio::DBus::NodeInfo::create_for_xml(GTG_INTERFACE);
       s_gtg_interface = node_info->lookup_interface("org.gnome.GTG");
-      if(s_gtg_interface == 0) {
+      if(!s_gtg_interface) {
         ERR_OUT(_("GTG XML loaded, but interface not found"));
         return;
       }
@@ -96,7 +96,7 @@ void ExportToGTGNoteAddin::export_button
   try {
     Glib::RefPtr<Gio::DBus::Proxy> proxy = Gio::DBus::Proxy::create_for_bus_sync(
         Gio::DBus::BUS_TYPE_SESSION, "org.gnome.GTG", "/org/gnome/GTG", "org.gnome.GTG", s_gtg_interface);
-    if(proxy == 0) {
+    if(!proxy) {
       ERR_OUT(_("Failed to create D-Bus proxy for GTG"));
       return;
     }
