--- ./imagesgallery/plugin_imagesgallery.cpp.orig	Sat Sep  4 11:37:02 2004
+++ ./imagesgallery/plugin_imagesgallery.cpp	Sat Sep  4 11:37:08 2004
@@ -32,7 +32,7 @@
 
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_imagesgallery,
-                            KGenericFactory<Plugin_Imagesgallery>("digikam"));
+                            KGenericFactory<Plugin_Imagesgallery>("digikam"))
 
 // -----------------------------------------------------------
 Plugin_Imagesgallery::Plugin_Imagesgallery(QObject *parent, const char*, const QStringList&)
