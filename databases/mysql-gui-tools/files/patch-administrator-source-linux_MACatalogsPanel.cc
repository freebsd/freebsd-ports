--- administrator/source/linux/MACatalogsPanel.cc.orig	2009-07-08 12:51:09.000000000 +0200
+++ administrator/source/linux/MACatalogsPanel.cc	2009-07-08 12:51:33.000000000 +0200
@@ -1488,7 +1488,7 @@
 
       _maint_dlg_xml->get_button("next_button")->set_sensitive(false);
       _maint_dlg_xml->get_note("note")->set_current_page(4);
-      SigC::Connection conn = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MACatalogsPanel::maint_pulse_progressbar), 200);
+      sigc::connection conn = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MACatalogsPanel::maint_pulse_progressbar), 200);
 
       status= (MYX_TABLE_COMMAND_STATUSES*)
         _data->get_instance()->perform_data_fetch3((MInstanceInfo::DataFetcher3)myx_optimize_table,
@@ -1528,7 +1528,7 @@
 
       _maint_dlg_xml->get_button("next_button")->set_sensitive(false);
       _maint_dlg_xml->get_note("note")->set_current_page(4);      
-      SigC::Connection conn = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MACatalogsPanel::maint_pulse_progressbar), 200);
+      sigc::connection conn = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MACatalogsPanel::maint_pulse_progressbar), 200);
 
       status= (MYX_TABLE_COMMAND_STATUSES*)
         _data->get_instance()->perform_data_fetch3((MInstanceInfo::DataFetcher3)myx_check_table,
@@ -1568,7 +1568,7 @@
 
       _maint_dlg_xml->get_button("next_button")->set_sensitive(false);
       _maint_dlg_xml->get_note("note")->set_current_page(4);
-      SigC::Connection conn = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MACatalogsPanel::maint_pulse_progressbar), 200);
+      sigc::connection conn = Glib::signal_timeout().connect(sigc::mem_fun(*this, &MACatalogsPanel::maint_pulse_progressbar), 200);
 
       status= (MYX_TABLE_COMMAND_STATUSES*)
         _data->get_instance()->perform_data_fetch3((MInstanceInfo::DataFetcher3)myx_repair_table,
