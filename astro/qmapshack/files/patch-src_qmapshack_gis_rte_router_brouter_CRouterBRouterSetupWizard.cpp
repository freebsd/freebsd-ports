--- src/qmapshack/gis/rte/router/brouter/CRouterBRouterSetupWizard.cpp.orig	2023-07-20 14:13:59 UTC
+++ src/qmapshack/gis/rte/router/brouter/CRouterBRouterSetupWizard.cpp
@@ -18,7 +18,7 @@
 
 #include "gis/rte/router/brouter/CRouterBRouterSetupWizard.h"
 
-#include <JlCompress.h>
+#include <quazip/JlCompress.h>
 
 #include <QFileDialog>
 #include <QMessageBox>
