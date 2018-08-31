Fix build with Qt 5.11

--- src/dialogs/preferences.cpp.orig	2018-08-31 00:53:54 UTC
+++ src/dialogs/preferences.cpp
@@ -21,6 +21,7 @@
 #include "engineoptiondialog.h"
 #include "downloadmanager.h"
 
+#include <QAction>
 #include <QCheckBox>
 #include <QColorDialog>
 #include <QComboBox>
