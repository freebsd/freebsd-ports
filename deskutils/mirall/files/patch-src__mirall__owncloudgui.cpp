--- src/mirall/owncloudgui.cpp.orig
+++ src/mirall/owncloudgui.cpp
@@ -31,6 +31,8 @@
 #include "openfilemanager.h"
 #include "creds/abstractcredentials.h"
 
+#include <climits>
+
 #include <QDesktopServices>
 #include <QMessageBox>
 #include <QSignalMapper>
