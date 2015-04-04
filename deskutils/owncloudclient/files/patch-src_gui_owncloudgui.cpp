--- src/gui/owncloudgui.cpp.orig	2015-03-16 14:28:58 UTC
+++ src/gui/owncloudgui.cpp
@@ -33,6 +33,8 @@
 #include "openfilemanager.h"
 #include "creds/abstractcredentials.h"
 
+#include <climits>
+
 #include <QDesktopServices>
 #include <QMessageBox>
 #include <QSignalMapper>
