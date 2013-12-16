--- AI/Skirmish/KAIK/AttackHandler.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/AttackHandler.cpp	2013-11-11 03:16:31.073773664 +0400
@@ -829,9 +829,9 @@
 
 		ai->pather->micropather->SetMapData(
 			ai->pather->MoveArrays[group_in->GetWorstMoveType()],
-			ai->tm->GetThreatArray(),
-			ai->tm->GetThreatMapWidth(),
-			ai->tm->GetThreatMapHeight()
+			ai->thm->GetThreatArray(),
+			ai->thm->GetThreatMapWidth(),
+			ai->thm->GetThreatMapHeight()
 		);
 
 
@@ -930,9 +930,9 @@
 	// in each group (movement map PATHTOUSE is hack)
 	ai->pather->micropather->SetMapData(
 		ai->pather->MoveArrays[PATHTOUSE],
-		ai->tm->GetThreatArray(),
-		ai->tm->GetThreatMapWidth(),
-		ai->tm->GetThreatMapHeight()
+		ai->thm->GetThreatArray(),
+		ai->thm->GetThreatMapWidth(),
+		ai->thm->GetThreatMapHeight()
 	);
 
 	// calculate and draw k-means for the base perimeters every 10 seconds
