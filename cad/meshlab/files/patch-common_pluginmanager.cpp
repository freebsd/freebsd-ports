--- common/pluginmanager.cpp.orig	2012-11-07 11:15:44.000000000 +0100
+++ common/pluginmanager.cpp	2012-11-07 11:16:26.000000000 +0100
@@ -230,7 +230,11 @@
 
 QString PluginManager::getPluginDirPath()
 {
+#ifdef __FreeBSD__
+  QDir pluginsDir("%%PREFIX%%/lib/meshlab/");
+#else
   QDir pluginsDir(getBaseDirPath());
+#endif
   if(!pluginsDir.exists("plugins"))
     //QMessageBox::warning(0,"Meshlab Initialization","Serious error. Unable to find the plugins directory.");
     qDebug("Meshlab Initialization: Serious error. Unable to find the plugins directory.");
