--- ui/zenoedit/util/apphelper.h.orig	2024-07-27 11:22:11 UTC
+++ ui/zenoedit/util/apphelper.h
@@ -1,19 +1,18 @@
 #ifndef __ZENOEDIT_HELPER__
 #define __ZENOEDIT_HELPER__
 
 #include <zenomodel/include/igraphsmodel.h>
-#include "zenoapplication.h"
 #include <zenomodel/include/graphsmanagment.h>
 #include <zenomodel/include/igraphsmodel.h>
-#include "zenomainwindow.h"
 #include <zenovis/ObjectsManager.h>
 #include <zeno/types/UserData.h>
-#include <zenoui/comctrl/gv/zveceditoritem.h>
-#include <viewport/viewportwidget.h>
 #include "launch/corelaunch.h"
 #include "settings/zsettings.h"
 #include "viewport/recordvideomgr.h"
 #include "panel/zenospreadsheet.h"
+
+class ZVecEditorItem;
+class ViewPortWidget;
 
 class AppHelper
 {
