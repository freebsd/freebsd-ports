--- AI/Skirmish/KAIK/Unit.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/Unit.cpp	2013-11-11 03:16:19.873774077 +0400
@@ -256,7 +256,7 @@
 			const FeatureDef* fDef    = ai->cb->GetFeatureDef(featureIDs[i]);
 			const float3&     fPos    = ai->cb->GetFeaturePos(featureIDs[i]);
 			const float       fDist   = fPos.distance2D(ai->cb->GetUnitPos(uid));
-			const float       fThreat = ai->tm->ThreatAtThisPoint(fPos);
+			const float       fThreat = ai->thm->ThreatAtThisPoint(fPos);
 
 			if (fDef == 0)
 				continue;
@@ -266,11 +266,11 @@
 				continue;
 			}
 
-			if (fDef->metal > bestScore && fThreat <= ai->tm->GetAverageThreat()) {
+			if (fDef->metal > bestScore && fThreat <= ai->thm->GetAverageThreat()) {
 				bestScore = fDef->metal;
 				bestFeatureID = featureIDs[i];
 			}
-			else if (bestScore == fDef->metal && fThreat <= ai->tm->GetAverageThreat()) {
+			else if (bestScore == fDef->metal && fThreat <= ai->thm->GetAverageThreat()) {
 				if (fDist < bestDist) {
 					bestFeatureID = featureIDs[i];
 					bestDist = fDist;
@@ -282,7 +282,7 @@
 			const FeatureDef* fDef    = ai->cb->GetFeatureDef(featureIDs[i]);
 			const float3&     fPos    = ai->cb->GetFeaturePos(featureIDs[i]);
 			const float       fDist   = fPos.distance2D(ai->cb->GetUnitPos(uid));
-			const float       fThreat = ai->tm->ThreatAtThisPoint(fPos);
+			const float       fThreat = ai->thm->ThreatAtThisPoint(fPos);
 
 			if (fDef == 0)
 				continue;
@@ -291,11 +291,11 @@
 				continue;
 			}
 
-			if (fDef->energy > bestScore && fThreat < ai->tm->GetAverageThreat()) {
+			if (fDef->energy > bestScore && fThreat < ai->thm->GetAverageThreat()) {
 				bestScore = fDef->energy;
 				bestFeatureID = featureIDs[i];
 			}
-			else if (bestScore == fDef->energy && fThreat < ai->tm->GetAverageThreat()) {
+			else if (bestScore == fDef->energy && fThreat < ai->thm->GetAverageThreat()) {
 				if (fDist < bestDist) {
 					bestFeatureID = featureIDs[i];
 					bestDist = fDist;
