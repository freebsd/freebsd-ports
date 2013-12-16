--- AI/Skirmish/KAIK/DefenseMatrix.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/DefenseMatrix.cpp	2013-11-11 03:16:52.800773805 +0400
@@ -84,7 +84,7 @@
 		int y = (int) (builderpos.z / f3multiplier);
 		float fastSumMap = sumMap[y * ai->pather->PathMapXSize + x];
 		float3 spotpos = float3(x * f3multiplier, 0, y * f3multiplier);
-		float myscore = fastSumMap / (builderpos.distance2D(spotpos) + averagemapsize / 8) * ((ai->pather->HeightMap[y * ai->pather->PathMapXSize + x] + 200) / (ai->pather->AverageHeight + 10)) / (ai->tm->ThreatAtThisPoint(spotpos) + 0.01);
+		float myscore = fastSumMap / (builderpos.distance2D(spotpos) + averagemapsize / 8) * ((ai->pather->HeightMap[y * ai->pather->PathMapXSize + x] + 200) / (ai->pather->AverageHeight + 10)) / (ai->thm->ThreatAtThisPoint(spotpos) + 0.01);
 		bestscore_fast = myscore;
 		bestspotx_fast = x;
 		bestspoty_fast = y;
@@ -131,7 +131,7 @@
 
 			float3 bestPosibleSpotpos = float3(bestX * f3multiplier, 0, bestY * f3multiplier);
 			// this must be guessed, set it to the best possible (slow)
-			float bestThreatAtThisPoint = 0.01 + ai->tm->GetAverageThreat() - 1;
+			float bestThreatAtThisPoint = 0.01 + ai->thm->GetAverageThreat() - 1;
 			float bestDistance = builderpos.distance2D(bestPosibleSpotpos);
 			float bestHeight = ai->pather->HeightMap[cachePoint->y * ai->pather->PathMapXSize + cachePoint->x] + 200;
 			float bestPosibleMyScore = bestScoreInThisBox / (bestDistance + averagemapsize / 4) * (bestHeight + 200) / bestThreatAtThisPoint;
@@ -145,7 +145,7 @@
 					for (int sy = y * CACHEFACTOR; sy < ai->pather->PathMapYSize && sy < (y * CACHEFACTOR + CACHEFACTOR); sy++) {
 						float fastSumMap = sumMap[sy * ai->pather->PathMapXSize + sx];
 						float3 spotpos = float3(sx * f3multiplier, 0, sy * f3multiplier);
-						float myscore = fastSumMap / (builderpos.distance2D(spotpos) + averagemapsize / 4) * (ai->pather->HeightMap[sy * ai->pather->PathMapXSize + sx]+200) / (ai->tm->ThreatAtThisPoint(spotpos) + 0.01);
+						float myscore = fastSumMap / (builderpos.distance2D(spotpos) + averagemapsize / 4) * (ai->pather->HeightMap[sy * ai->pather->PathMapXSize + sx]+200) / (ai->thm->ThreatAtThisPoint(spotpos) + 0.01);
 						// THIS COULD BE REALLY SLOW!
 						if (myscore > bestscore_fast && BuildMaskArray[sy * ai->pather->PathMapXSize + sx] == 0 && ai->cb->CanBuildAt(def, spotpos)) {
 							bestscore_fast = myscore;
@@ -199,7 +199,7 @@
 	}
 
 	spotFinder->InvalidateSumMap(x, y, Range + 1);
-	// ai->debug->MakeBWTGA(Chokepointmap, ai->tm->GetThreatMapWidth(), ai->tm->GetThreatMapHeight(), "DebugPathMatrix", 1);
+	// ai->debug->MakeBWTGA(Chokepointmap, ai->thm->GetThreatMapWidth(), ai->thm->GetThreatMapHeight(), "DebugPathMatrix", 1);
 }
 
 
