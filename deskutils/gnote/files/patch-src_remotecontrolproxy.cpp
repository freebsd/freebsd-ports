--- src/remotecontrolproxy.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/remotecontrolproxy.cpp
@@ -35,7 +35,7 @@ namespace {
   void load_interface_from_file(const char *filename, const char *interface_name,
                                 Glib::RefPtr<Gio::DBus::InterfaceInfo> & interface)
   {
-    if(interface != 0) {
+    if(interface) {
       return;
     }
     std::ifstream fin(filename);
