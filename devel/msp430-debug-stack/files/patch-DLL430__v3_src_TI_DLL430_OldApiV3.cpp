--- DLL430_v3/src/DLL430_OldApiV3.cpp.orig	2016-11-21 17:51:22.765156000 +0300
+++ DLL430_v3/src/DLL430_OldApiV3.cpp	2016-11-21 17:53:00.428191000 +0300
@@ -958,7 +958,7 @@
 				}
 				else
 				{
-					cm->reset(false, true, 0, NULL);
+					cm->reset(false, true, 0, 0);
 					cm->setJtagMode(SWD_MSP432);
 					selectedMode = SWD_MSP432;
 					cm->start();
