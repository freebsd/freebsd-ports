--- ./rawconverter/plugin_rawconverter.cpp.orig	Sat Sep  4 11:44:10 2004
+++ ./rawconverter/plugin_rawconverter.cpp	Sat Sep  4 11:44:18 2004
@@ -45,7 +45,7 @@
 #include "batchdialog.h"
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_rawconverter,
-                            KGenericFactory<Plugin_RawConverter>("digikam"));
+                            KGenericFactory<Plugin_RawConverter>("digikam"))
 
 
 Plugin_RawConverter::Plugin_RawConverter(QObject *parent,
