--- src/plugins/projectexplorer/customwizard/customwizard.cpp.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/projectexplorer/customwizard/customwizard.cpp
@@ -28,8 +28,9 @@
 #include "customwizardpage.h"
 #include "customwizardscriptgenerator.h"
 
-#include <projectexplorer/projectexplorer.h>
 #include <projectexplorer/baseprojectwizarddialog.h>
+#include <projectexplorer/projectexplorer.h>
+#include <projectexplorer/runconfiguration.h>
 
 #include <coreplugin/icore.h>
 #include <coreplugin/messagemanager.h>
