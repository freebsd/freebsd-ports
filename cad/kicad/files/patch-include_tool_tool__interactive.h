--- include/tool/tool_interactive.h.orig	2017-07-14 19:17:29 UTC
+++ include/tool/tool_interactive.h
@@ -26,6 +26,7 @@
 #define __TOOL_INTERACTIVE_H
 
 #include <string>
+#include <functional>
 
 #include <tool/tool_event.h>
 #include <tool/tool_base.h>
@@ -113,7 +114,8 @@ template <class T>
 void TOOL_INTERACTIVE::Go( int (T::* aStateFunc)( const TOOL_EVENT& ),
                            const TOOL_EVENT_LIST& aConditions )
 {
-    TOOL_STATE_FUNC sptr( static_cast<T*>( this ), aStateFunc );
+// Patch obtained from https://git.archlinux.org/svntogit/community.git/tree/trunk/boost-1.61.patch?h=packages/kicad
+    TOOL_STATE_FUNC sptr = std::bind( aStateFunc, static_cast<T*>( this ), std::placeholders::_1 );
 
     goInternal( sptr, aConditions );
 }
