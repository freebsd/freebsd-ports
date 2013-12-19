--- rts/Sim/Misc/DefinitionTag.h.orig	2013-12-06 22:23:53.818446384 +0400
+++ rts/Sim/Misc/DefinitionTag.h	2013-12-06 22:42:16.128369497 +0400
@@ -15,7 +15,6 @@
 #include <typeinfo>
 #include "Lua/LuaParser.h"
 #include "System/float3.h"
-#include "System/Util.h"
 
 //example usage: DUMMYTAG(Defs, DefClass, table, customParams)
 struct table {};
@@ -43,6 +42,7 @@
 	}
 };
 
+#include "System/Util.h"
 
 /**
  * @brief Untyped definition tag meta data.
