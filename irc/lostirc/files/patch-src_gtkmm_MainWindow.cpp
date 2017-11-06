--- src/gtkmm/MainWindow.cpp.orig	2017-04-05 11:24:58 UTC
+++ src/gtkmm/MainWindow.cpp
@@ -485,7 +485,7 @@ void MainWindow::openAboutWindow()
     if (_aboutwin.get()) {
           _aboutwin->present();
     } else {
-        std::auto_ptr<Gtk::MessageDialog> dialog(new Gtk::MessageDialog(_("LostIRC "VERSION), false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false));
+        std::auto_ptr<Gtk::MessageDialog> dialog(new Gtk::MessageDialog(_("LostIRC " VERSION), false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false));
 
         dialog->signal_response().connect(sigc::mem_fun(*this, &MainWindow::hideAboutWindow));
         dialog->show();
