--- src/qmapshack/gis/rte/router/brouter/CRouterBRouterSetupWizard.cpp.orig	2021-05-24 09:18:08 UTC
+++ src/qmapshack/gis/rte/router/brouter/CRouterBRouterSetupWizard.cpp
@@ -24,7 +24,7 @@
 #include "helpers/CWebPage.h"
 #include "setup/IAppSetup.h"
 
-#include <JlCompress.h>
+#include <quazip/JlCompress.h>
 #include <QFileDialog>
 #include <QMessageBox>
 #include <QNetworkReply>
