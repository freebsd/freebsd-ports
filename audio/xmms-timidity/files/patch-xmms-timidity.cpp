--- xmms-timidity.cpp.orig	2005-07-21 09:44:56 UTC
+++ xmms-timidity.cpp
@@ -347,7 +347,7 @@ void setSongTitle(void)
 
 void *infoThread(void *pData)
 {
-	int pipeTimidity = (int)pData;
+	long pipeTimidity = (long)pData;
 	char cLine[256];
 	signed int iBytes = 1;
 	while ((iBytes > 0) && (::bPlaying)) {
