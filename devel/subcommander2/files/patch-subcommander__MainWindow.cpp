--- subcommander/MainWindow.cpp.orig	2009-01-11 23:46:56.000000000 +0900
+++ subcommander/MainWindow.cpp	2012-05-10 05:51:23.000000000 +0900
@@ -260,7 +260,7 @@
 void MainWindow::settings( const QString& selected )
 {
   SettingsDialog* sd = new SettingsDialog( _q("subcommander:settings"), this );
-  SettingsInfo*   si;
+  //SettingsInfo*   si;
 
 #if 0
   // projects root item
