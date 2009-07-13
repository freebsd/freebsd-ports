--- administrator/source/linux/MARestorePanel.cc.orig	2009-07-08 12:49:02.000000000 +0200
+++ administrator/source/linux/MARestorePanel.cc	2009-07-08 12:49:13.000000000 +0200
@@ -728,7 +728,7 @@
   op_aborted= false;
 
   {
-    SigC::Connection con= Glib::signal_timeout().connect(sigc::bind<void*>
+    sigc::connection con= Glib::signal_timeout().connect(sigc::bind<void*>
                                                          (sigc::mem_fun(*this, &MARestorePanel::update_status),&arg.pdata),
                                                          50);
 
@@ -854,7 +854,7 @@
   //{
     MYX_BACKUP_ERROR err;
 
-    SigC::Connection con= Glib::signal_timeout().connect(sigc::bind<void*>
+    sigc::connection con= Glib::signal_timeout().connect(sigc::bind<void*>
                                                          (sigc::mem_fun(*this, &MARestorePanel::update_status),&arg.pdata),
                                                          50);
 
