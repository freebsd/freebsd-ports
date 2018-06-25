--- src/ai/ai_plan.cpp.orig	2016-11-08 14:38:09 UTC
+++ src/ai/ai_plan.cpp
@@ -343,7 +343,7 @@ int GetTotalBoardCapacity(ITERATOR begin
 int AiForce::PlanAttack()
 {
 	CPlayer &player = *AiPlayer->Player;
-	DebugPrint("%d: Planning for force #%lu of player #%d\n"_C_ player.Index
+	DebugPrint("%d: Planning for force #%lu of player #%d\n" _C_ player.Index
 			   _C_(long unsigned int)(this - & (AiPlayer->Force[0])) _C_ player.Index);
 
 	TerrainTraversal transporterTerrainTraversal;
