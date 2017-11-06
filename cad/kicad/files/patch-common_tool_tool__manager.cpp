--- common/tool/tool_manager.cpp.orig	2017-07-14 19:17:29 UTC
+++ common/tool/tool_manager.cpp
@@ -27,6 +27,7 @@
 #include <list>
 #include <stack>
 #include <algorithm>
+#include <functional>
 
 #include <boost/foreach.hpp>
 #include <boost/scoped_ptr.hpp>
@@ -542,11 +543,12 @@ void TOOL_MANAGER::dispatchInternal( con
                     if( st->cofunc )
                         st->Push();
 
+// Patch obtained from https://git.archlinux.org/svntogit/community.git/tree/trunk/boost-1.61.patch?h=packages/kicad
+                    st->cofunc = new COROUTINE<int, const TOOL_EVENT&>( tr.second );
+
                     // as the state changes, the transition table has to be set up again
                     st->transitions.clear();
 
-                    st->cofunc = new COROUTINE<int, const TOOL_EVENT&>( tr.second );
-
                     // got match? Run the handler.
                     st->cofunc->Call( aEvent );
 
