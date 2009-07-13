--- administrator/source/linux/MAdministrator.h.orig	2009-07-08 11:51:36.000000000 +0200
+++ administrator/source/linux/MAdministrator.h	2009-07-08 11:55:04.000000000 +0200
@@ -66,7 +66,7 @@
 
     sigc::signal0<void> _signal_prefs_changed;
     
-    SigC::Connection _pulse_conn;
+    sigc::connection _pulse_conn;
     bool pulse_progress();
     
     void setup_sidebar();
