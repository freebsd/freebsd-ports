--- AI/Skirmish/KAIK/MetalMap.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/MetalMap.cpp	2013-11-11 03:17:46.615772673 +0400
@@ -57,7 +57,7 @@
 
 			if (spotCoords.x >= 0.0f) {
 				float distance = spotCoords.distance2D(ai->cb->GetUnitPos(builderid)) + 150;
-				float myThreat = ai->tm->ThreatAtThisPoint(spotCoords);
+				float myThreat = ai->thm->ThreatAtThisPoint(spotCoords);
 				float spotScore = VectoredSpots[i].y / distance / (myThreat + 10);
 
 				// along with threatmap try to search for enemy armed units around cause
@@ -92,7 +92,7 @@
 				// by presence of ARMED enemy units or buildings
 				bool b1 = (TempScore < spotScore);
 				bool b2 = (numEnemies == 0);
-				bool b3 = (myThreat <= (ai->tm->GetAverageThreat() * 1.5));
+				bool b3 = (myThreat <= (ai->thm->GetAverageThreat() * 1.5));
 				bool b4 = (ai->uh->TaskPlanExist(spotCoords, extractor));
 
 				if (b1 && b2 && b3 && !b4 && !bOccupied) {
