--- ./sendimages/plugin_sendimages.cpp.orig	Sat Sep  4 11:45:40 2004
+++ ./sendimages/plugin_sendimages.cpp	Sat Sep  4 11:45:47 2004
@@ -41,7 +41,7 @@
 
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_sendimages,
-                            KGenericFactory<Plugin_SendImages>("digikam"));
+                            KGenericFactory<Plugin_SendImages>("digikam"))
 
 // -----------------------------------------------------------
 Plugin_SendImages::Plugin_SendImages(QObject *parent, const char*, const QStringList&)
