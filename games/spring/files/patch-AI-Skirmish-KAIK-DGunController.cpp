--- AI/Skirmish/KAIK/DGunController.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/DGunController.cpp	2013-11-11 03:17:24.007772549 +0400
@@ -166,7 +166,7 @@
 			if (canDGun) {
 				IssueOrder(dgunPos, CMD_DGUN, 0);
 			} else {
-				bool bDanger = ai->tm->ThreatAtThisPoint(commanderPos/*curTargetPos*/) > ai->tm->GetAverageThreat();
+				bool bDanger = ai->thm->ThreatAtThisPoint(commanderPos/*curTargetPos*/) > ai->thm->GetAverageThreat();
 
 				if (bDanger) {
 					state.Reset(currentFrame, true);
