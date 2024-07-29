--- ui/zenoedit/util/apphelper.cpp.orig	2023-11-22 19:17:26 UTC
+++ ui/zenoedit/util/apphelper.cpp
@@ -11,7 +11,11 @@
 #include <zeno/core/Session.h>
 #include <zeno/extra/GlobalComm.h>
 #include "viewport/zoptixviewport.h"
+#include "timeline/ztimeline.h"
+#include "zenomodel/include/curveutil.h"
+#include "zenomodel/include/nodesmgr.h"
 
+#include "zenoapplication.h"
 
 QModelIndexList AppHelper::getSubInOutNode(IGraphsModel* pModel, const QModelIndex& subgIdx, const QString& sockName, bool bInput)
 {
