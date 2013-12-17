--- ./src/CReplayData.cpp.orig	2011-04-17 16:56:56.000000000 +0200
+++ ./src/CReplayData.cpp	2013-12-08 23:21:23.000000000 +0100
@@ -38,7 +38,8 @@
 
 void ReplayData::printReplayInformation()
 {
-	tm *timeinfo = localtime(&header.randomSeed);
+	time_t t = header.randomSeed;
+	tm *timeinfo = localtime(&t);
 	printf("Recorded on : %s", asctime(timeinfo));
 	printf("Map         : %s\n", header.map);
 	printf("Score       : %d\n", header.score);
