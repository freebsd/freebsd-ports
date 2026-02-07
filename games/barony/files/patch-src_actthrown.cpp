--- src/actthrown.cpp.orig	2022-10-30 18:49:17 UTC
+++ src/actthrown.cpp
@@ -261,7 +261,7 @@ void actThrown(Entity* my)
 			else if ( type == TOOL_SENTRYBOT || type == TOOL_SPELLBOT )
 			{
 				my->roll += 0.07;
-				my->roll = std::min(my->roll, 0.0);
+				my->roll = std::min(my->roll, (real_t)0.0);
 			}
 			else
 			{
