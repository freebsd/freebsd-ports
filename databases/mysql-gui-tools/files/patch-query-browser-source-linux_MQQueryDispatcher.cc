--- query-browser/source/linux/MQQueryDispatcher.cc.orig	2009-07-16 16:30:10.000000000 +0200
+++ query-browser/source/linux/MQQueryDispatcher.cc	2009-07-16 16:33:04.000000000 +0200
@@ -558,9 +558,6 @@
 
   Gtk::Main::instance()->run();
 
-  while(!req->is_complete())
-    ;
-
   return sps;
 }
 
