--- ./miscsoperations/plugin_miscsoperations.cpp.orig	Sat Sep  4 11:39:39 2004
+++ ./miscsoperations/plugin_miscsoperations.cpp	Sat Sep  4 11:39:46 2004
@@ -39,7 +39,7 @@
  // plugin library and the second is the genericfactory templated from
  // the class for your plugin
  K_EXPORT_COMPONENT_FACTORY( digikamplugin_miscsoperations,
-                            KGenericFactory<Plugin_MiscsOperations>("digikam"));
+                            KGenericFactory<Plugin_MiscsOperations>("digikam"))
 
  Plugin_MiscsOperations::Plugin_MiscsOperations(QObject *parent,
                                     const char*,
