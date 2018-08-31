Fix build with Qt 5.11

--- src/dialogs/savedialog.cpp.orig	2018-08-31 00:54:35 UTC
+++ src/dialogs/savedialog.cpp
@@ -22,6 +22,7 @@
 #include "settings.h"
 #include "tags.h"
 
+#include <QButtonGroup>
 #include <QLineEdit>
 #include <QCompleter>
 
