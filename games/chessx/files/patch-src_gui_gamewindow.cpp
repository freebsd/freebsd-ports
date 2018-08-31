Fix build with Qt 5.11

--- src/gui/gamewindow.cpp.orig	2018-08-31 00:55:39 UTC
+++ src/gui/gamewindow.cpp
@@ -8,6 +8,7 @@
 #include "nag.h"
 #include "settings.h"
 
+#include <QAction>
 #include <QToolButton>
 
 #if defined(_MSC_VER) && defined(_DEBUG)
