--- src/VBox/Frontends/VirtualBox/src/settings/vm/VBoxVMSettingsHD.h.orig	2010-06-04 10:43:02.000000000 +0200
+++ src/VBox/Frontends/VirtualBox/src/settings/vm/VBoxVMSettingsHD.h	2010-06-04 10:33:40.000000000 +0200
@@ -20,7 +20,7 @@
 #define __VBoxVMSettingsHD_h__
 
 /* Global includes */
-#include <qglobal.h> /* for Q_WS_MAC */
+#include <QtGlobal> /* for Q_WS_MAC */
 #ifdef Q_WS_MAC
 /* Somewhere Carbon.h includes AssertMacros.h which defines the macro "check".
  * In QItemDelegate a class method is called "check" also. As we not used the
