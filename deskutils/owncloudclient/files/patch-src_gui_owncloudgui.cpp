--- src/gui/owncloudgui.cpp.orig	2017-12-20 15:03:02 UTC
+++ src/gui/owncloudgui.cpp
@@ -35,6 +35,8 @@
 #include "common/syncjournalfilerecord.h"
 #include "creds/abstractcredentials.h"
 
+#include <climits>
+
 #include <QDesktopServices>
 #include <QDir>
 #include <QMessageBox>
