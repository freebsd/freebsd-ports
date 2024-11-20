--- ui/zenoedit/nodesys/zenonode.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/nodesys/zenonode.cpp
@@ -34,6 +34,7 @@
 #include "settings/zenosettingsmanager.h"
 #include <zenomodel/include/command.h>
 #include <zenomodel/include/nodeparammodel.h>
+#include <comctrl/gv/zveceditoritem.h>
 
 
 ZenoNode::ZenoNode(const NodeUtilParam &params, QGraphicsItem *parent)
