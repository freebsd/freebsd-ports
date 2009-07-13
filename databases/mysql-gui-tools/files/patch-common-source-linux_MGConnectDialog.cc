--- common/source/linux/MGConnectDialog.cc.orig	2006-12-05 23:44:08.000000000 +0100
+++ common/source/linux/MGConnectDialog.cc	2007-11-08 16:21:54.000000000 +0100
@@ -659,9 +659,9 @@ void MGConnectDialog::open_connection_ed
   // select back the original item
   ((Gtk::OptionMenu*)_xml->get_widget("connection_list"))->set_history(_current_selected_item);
 
-  SigC::Connection c1= MGPreferencesEditor::instance()->signal_closed().connect(sigc::mem_fun(*this,
+  sigc::connection c1= MGPreferencesEditor::instance()->signal_closed().connect(sigc::mem_fun(*this,
                                                                                            &MGConnectDialog::preferences_closed));
-  SigC::Connection c2= MGPreferencesEditor::instance()->signal_changed().connect(sigc::mem_fun(*this,
+  sigc::connection c2= MGPreferencesEditor::instance()->signal_changed().connect(sigc::mem_fun(*this,
                                                                                             &MGConnectDialog::preferences_changed));
   MGPreferencesEditor::instance()->show(true);
   MGPreferencesEditor::instance()->set_modal(true);
@@ -676,7 +676,7 @@ void MGConnectDialog::show_connection_fa
 {
   Gtk::Button *btn;
   pid_t ping_pid= 0;
-  SigC::Connection input_handler;
+  sigc::connection input_handler;
   int rc;
   bool pinging= false;
   int myerror= 0;

