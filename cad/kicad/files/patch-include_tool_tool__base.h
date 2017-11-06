--- include/tool/tool_base.h.orig	2017-07-14 19:17:29 UTC
+++ include/tool/tool_base.h
@@ -31,7 +31,8 @@
 #include <tool/tool_event.h>
 #include <tool/tool_settings.h>
 
-#include <tool/delegate.h>
+// Patch obtained from https://git.archlinux.org/svntogit/community.git/tree/trunk/boost-1.61.patch?h=packages/kicad
+#include <functional>
 
 class EDA_ITEM;
 class TOOL_MANAGER;
@@ -53,7 +54,8 @@ enum TOOL_TYPE
 
 /// Unique identifier for tools
 typedef int TOOL_ID;
-typedef DELEGATE<int, const TOOL_EVENT&> TOOL_STATE_FUNC;
+
+using TOOL_STATE_FUNC = std::function<int(const TOOL_EVENT&)>;
 
 /**
  * Class TOOL_BASE
