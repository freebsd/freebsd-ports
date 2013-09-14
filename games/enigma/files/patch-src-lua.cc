--- src/lua.cc.orig	2007-09-08 16:20:02.000000000 +0400
+++ src/lua.cc	2013-09-14 02:32:22.905227099 +0400
@@ -171,7 +171,7 @@
     if (lua_isnil(L,idx))
         return 0;
 
-    if (!is_object(L,idx)) {
+    if (!::is_object(L,idx)) {
         throwLuaError(L, "Cannot convert type to an Object");
         return 0;
     }
@@ -294,7 +294,7 @@
 
     if (lua_isnil(L, 3))
         fl = 0;
-    else if (is_object(L,3)) {
+    else if (::is_object(L,3)) {
         fl = static_cast<Floor*>(*(static_cast<void**> (lua_touserdata(L,3))));
     	if( ! fl)
 	    throwLuaError(L, "object is no valid floor");
