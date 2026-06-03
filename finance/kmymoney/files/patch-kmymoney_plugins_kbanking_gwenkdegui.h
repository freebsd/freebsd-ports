We moved the devel/gwenhywfar-qt6 headers to prevent conflict with
devel/gwenhywfar-qt5.

--- kmymoney/plugins/kbanking/gwenkdegui.h.orig	2025-08-04 11:03:25 UTC
+++ kmymoney/plugins/kbanking/gwenkdegui.h
@@ -10,8 +10,8 @@
 
 #include <QObject>
 
-#include "gwen-gui-qt5/qt5_gui.hpp"
-#include "gwen-gui-qt5/qt5_gui_dialog.hpp"
+#include "gwen-gui-qt6/qt5_gui.hpp"
+#include "gwen-gui-qt6/qt5_gui_dialog.hpp"
 
 /**
  * @brief Gwenhywfar Gui by KDE
