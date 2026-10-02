--- src/gsiqt/qtbasic/gsiQtGuiExternals.h.orig	2026-10-01 19:08:46 UTC
+++ src/gsiqt/qtbasic/gsiQtGuiExternals.h
@@ -20,6 +20,7 @@
 
 */
 
+#include <QtGlobal>
 #if QT_VERSION >= 0x060000
 #  include "../qt6/QtGui/gsiQtExternals.h"
 #elif QT_VERSION >= 0x050000
