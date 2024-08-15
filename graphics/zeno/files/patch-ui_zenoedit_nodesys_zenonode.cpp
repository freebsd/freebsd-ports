--- ui/zenoedit/nodesys/zenonode.cpp.orig	2024-04-26 16:28:26 UTC
+++ ui/zenoedit/nodesys/zenonode.cpp
@@ -35,6 +35,7 @@
 #include "settings/zenosettingsmanager.h"
 #include <zenomodel/include/command.h>
 #include <zenomodel/include/nodeparammodel.h>
+#include <comctrl/gv/zveceditoritem.h>
 
 
 ZenoNode::ZenoNode(const NodeUtilParam &params, QGraphicsItem *parent)
@@ -2079,4 +2080,4 @@ void ZenoNode::onCustomNameChanged()
             m_pCategoryItem->setText(text);
         ZGraphicsLayout::updateHierarchy(m_pCategoryItem);
     }
 }
+}
