--- administrator/source/linux/MAServerConnectionsPanel.h.orig	2009-07-08 12:01:06.000000000 +0200
+++ administrator/source/linux/MAServerConnectionsPanel.h	2009-07-08 12:01:13.000000000 +0200
@@ -87,7 +87,7 @@
 
     Glib::RefPtr<Gdk::Pixbuf> _thread_icon;
 
-    SigC::Connection _timer;
+    sigc::connection _timer;
     
     int _current_page;
 
