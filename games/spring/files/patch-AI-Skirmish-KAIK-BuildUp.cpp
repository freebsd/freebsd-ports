--- AI/Skirmish/KAIK/BuildUp.cpp.orig	2013-03-26 03:58:45.000000000 +0400
+++ AI/Skirmish/KAIK/BuildUp.cpp	2013-11-11 03:15:30.794774021 +0400
@@ -32,7 +32,7 @@
 void CBuildUp::Update(int frame) {
 	if (frame % 15 == 0) {
 		// update current threat map
-		ai->tm->Update();
+		ai->thm->Update();
 		ai->uh->UpdateUpgradeTasks(frame);
 
 		GetEconState(&econState);
