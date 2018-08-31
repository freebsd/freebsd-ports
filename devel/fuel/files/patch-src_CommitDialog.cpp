Fix build with Qt 5.11

--- src/CommitDialog.cpp.orig	2018-08-31 10:17:37 UTC
+++ src/CommitDialog.cpp
@@ -1,4 +1,5 @@
 #include "CommitDialog.h"
+#include <QAction>
 #include <QPushButton>
 #include <QShortcut>
 #include "ui_CommitDialog.h"
