--- src/framework/bindings/lua/eris/lua_Eris.cpp.orig	2009-04-05 12:00:12.000000000 +0200
+++ src/framework/bindings/lua/eris/lua_Eris.cpp	2009-04-05 12:00:22.000000000 +0200
@@ -14,6 +14,7 @@
 TOLUA_API int  tolua_Eris_open (lua_State* tolua_S);
 
 #include "required.h"
+#include <Atlas/Objects/Operation.h>
 #include <Eris/Types.h>
 #include <Eris/Entity.h>
 #include <Eris/ServerInfo.h>
