--- src/gui/owncloudgui.cpp.orig	2016-05-12 07:59:12 UTC
+++ src/gui/owncloudgui.cpp
@@ -34,6 +34,8 @@
 #include "accountmanager.h"
 #include "creds/abstractcredentials.h"
 
+#include <climits>
+
 #include <QDesktopServices>
 #include <QDir>
 #include <QMessageBox>
