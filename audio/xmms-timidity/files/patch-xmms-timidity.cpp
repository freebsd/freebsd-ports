--- xmms-timidity.cpp.orig	2005-07-21 02:44:56.000000000 -0700
+++ xmms-timidity.cpp	2009-07-19 22:30:38.000000000 -0700
@@ -347,7 +347,7 @@
 
 void *infoThread(void *pData)
 {
-	int pipeTimidity = (int)pData;
+	long pipeTimidity = (long)pData;
 	char cLine[256];
 	signed int iBytes = 1;
 	while ((iBytes > 0) && (::bPlaying)) {
