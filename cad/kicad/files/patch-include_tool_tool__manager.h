--- include/tool/tool_manager.h.orig	2017-07-14 19:17:29 UTC
+++ include/tool/tool_manager.h
@@ -29,6 +29,7 @@
 #include <deque>
 #include <typeinfo>
 #include <map>
+#include <list>
 
 #include <tool/tool_base.h>
 
@@ -278,6 +279,8 @@ public:
     void ScheduleNextState( TOOL_BASE* aTool, TOOL_STATE_FUNC& aHandler,
             const TOOL_EVENT_LIST& aConditions );
 
+    void RunMainStack( TOOL_BASE* aTool, std::function<void()> aFunc );
+
     /**
      * Pauses execution of a given tool until one or more events matching aConditions arrives.
      * The pause/resume operation is done through COROUTINE object.
