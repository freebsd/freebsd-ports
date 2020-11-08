--- src/qmapshack/gis/rte/router/brouter/CRouterBRouterSetupWizard.cpp.orig	2020-11-08 17:59:37 UTC
+++ src/qmapshack/gis/rte/router/brouter/CRouterBRouterSetupWizard.cpp
@@ -22,7 +22,7 @@
 #include "gis/rte/router/brouter/CRouterBRouterSetupWizard.h"
 #include "helpers/CWebPage.h"
 #include "setup/IAppSetup.h"
-#include <JlCompress.h>
+#include <quazip/JlCompress.h>
 #include <proj_api.h>
 #include <QFileDialog>
 #include <QMessageBox>
