--- src/gui/owncloudgui.cpp.orig	2020-12-21 16:16:36 UTC
+++ src/gui/owncloudgui.cpp
@@ -32,6 +32,8 @@
 #include "creds/abstractcredentials.h"
 #include "guiutility.h"
 
+#include <climits>
+
 #include <QDesktopServices>
 #include <QDir>
 #include <QMessageBox>
