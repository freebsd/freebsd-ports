--- ./acquireimages/plugin_acquireimages.cpp.orig	Sat Sep  4 11:32:24 2004
+++ ./acquireimages/plugin_acquireimages.cpp	Sat Sep  4 11:32:45 2004
@@ -40,7 +40,7 @@
 
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_acquireimages,
-                            KGenericFactory<Plugin_AcquireImages>("digikam"));
+                            KGenericFactory<Plugin_AcquireImages>("digikam"))
 
 // -----------------------------------------------------------
 Plugin_AcquireImages::Plugin_AcquireImages(QObject *parent, const char*, const QStringList&)
