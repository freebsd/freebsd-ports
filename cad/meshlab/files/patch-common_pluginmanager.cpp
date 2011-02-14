--- common/pluginmanager.cpp.orig	2011-02-07 14:11:51.000000000 +0100
+++ common/pluginmanager.cpp	2011-02-07 14:12:33.000000000 +0100
@@ -98,7 +98,11 @@
 
 QString PluginManager::getPluginDirPath()
 {
+#ifdef __FreeBSD__
+	QDir pluginsDir("%%PREFIX%%/lib/meshlab/");
+#else
 	QDir pluginsDir(getBaseDirPath());
+#endif
 	if(!pluginsDir.exists("plugins"))
 		//QMessageBox::warning(0,"Meshlab Initialization","Serious error. Unable to find the plugins directory.");
 		qDebug("Meshlab Initialization: Serious error. Unable to find the plugins directory.");
