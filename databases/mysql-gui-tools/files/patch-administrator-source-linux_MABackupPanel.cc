--- administrator/source/linux/MABackupPanel.cc.orig	2009-07-08 12:06:17.000000000 +0200
+++ administrator/source/linux/MABackupPanel.cc	2009-07-08 12:06:37.000000000 +0200
@@ -1282,7 +1282,7 @@
 
   if (_inst->check_connection())
   {
-    SigC::Connection con= Glib::signal_timeout().connect(sigc::bind<void*>
+    sigc::connection con= Glib::signal_timeout().connect(sigc::bind<void*>
                                                          (sigc::mem_fun(*this, &MABackupPanel::update_backup_progress),&arg.pdata),
                                                          50);
     dlg->show();
