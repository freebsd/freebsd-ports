--- src/plugins/projectexplorer/devicesupport/desktopdevice.cpp.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/projectexplorer/devicesupport/desktopdevice.cpp
@@ -30,6 +30,7 @@
 #include "desktopdeviceconfigurationwidget.h"
 #include "desktopprocesssignaloperation.h"
 #include <projectexplorer/projectexplorerconstants.h>
+#include <projectexplorer/runnables.h>
 
 #include <ssh/sshconnection.h>
 
