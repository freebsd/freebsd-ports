--- ./cdarchiving/plugin_cdarchiving.cpp.orig	Sat Sep  4 11:34:46 2004
+++ ./cdarchiving/plugin_cdarchiving.cpp	Sat Sep  4 11:34:56 2004
@@ -32,7 +32,7 @@
 
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_cdarchiving,
-                            KGenericFactory<Plugin_CDArchiving>("digikam"));
+                            KGenericFactory<Plugin_CDArchiving>("digikam"))
 
 // -----------------------------------------------------------
 Plugin_CDArchiving::Plugin_CDArchiving(QObject *parent, const char*, const QStringList&)
