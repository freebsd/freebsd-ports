--- main.cpp.orig	2021-12-22 15:45:02 UTC
+++ main.cpp
@@ -1,13 +1,12 @@
 #include "mainwindow.h"
 #include <gtkmm/application.h>
 
-CMainWindow *mainwindow;
-
 int main (int argc, char *argv[])
 {
 	Gsv::init();
 	
 	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.github.blackhole89.notekit");
+	CMainWindow *mainwindow;
 	
 	app->signal_activate().connect( [app,&mainwindow]() {
 			mainwindow=new CMainWindow(app);
