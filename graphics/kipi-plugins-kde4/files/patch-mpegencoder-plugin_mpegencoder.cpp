--- ./mpegencoder/plugin_mpegencoder.cpp.orig	Sat Sep  4 11:40:24 2004
+++ ./mpegencoder/plugin_mpegencoder.cpp	Sat Sep  4 11:40:30 2004
@@ -37,7 +37,7 @@
 
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_mpegencoder,
-                            KGenericFactory<Plugin_Mpegencoder>("digikam"));
+                            KGenericFactory<Plugin_Mpegencoder>("digikam"))
 
 // -----------------------------------------------------------
 
