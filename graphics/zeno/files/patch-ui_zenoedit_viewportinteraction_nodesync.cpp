--- ui/zenoedit/viewportinteraction/nodesync.cpp.orig	2024-04-26 16:47:28 UTC
+++ ui/zenoedit/viewportinteraction/nodesync.cpp
@@ -1,3 +1,4 @@
+#include "zenoapplication.h"
 #include "nodesync.h"
 #include <zenomodel/include/uihelper.h>
 
@@ -205,4 +206,4 @@ std::string NodeSyncMgr::getPrimSockName(NodeLocation&
     return getPrimSockName(node_type.toStdString());
 }
 
 }
+}
