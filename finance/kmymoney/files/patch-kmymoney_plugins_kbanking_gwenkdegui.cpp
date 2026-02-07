We moved the devel/gwenhywfar-qt6 headers to prevent conflict with
devel/gwenhywfar-qt5.

--- kmymoney/plugins/kbanking/gwenkdegui.cpp.orig	2025-08-04 11:03:25 UTC
+++ kmymoney/plugins/kbanking/gwenkdegui.cpp
@@ -8,7 +8,7 @@
 #include "gwenkdegui.h"
 
 #include <gwenhywfar/debug.h>
-#include "gwen-gui-qt5/qt5dialogbox.hpp"
+#include "gwen-gui-qt6/qt5dialogbox.hpp"
 
 
 #include <QString>
