--- ./printwizard/plugin_printwizard.cpp.orig	Sat Sep  4 11:42:03 2004
+++ ./printwizard/plugin_printwizard.cpp	Sat Sep  4 11:42:15 2004
@@ -39,7 +39,7 @@
 #include "frmprintwizard.h"
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_printwizard,
-                            KGenericFactory<Plugin_PrintWizard>("digikam"));
+                            KGenericFactory<Plugin_PrintWizard>("digikam"))
 
 Plugin_PrintWizard::Plugin_PrintWizard(QObject *parent,
                                    const char*,
