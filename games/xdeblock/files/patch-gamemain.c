--- gamemain.c.orig	Sat Nov 16 14:37:16 1996
+++ gamemain.c	Mon Nov  3 15:30:25 2003
@@ -793,14 +793,13 @@
 void openingString(void)
 {
   XRectangle   	tempRect;
-  register	tempNum,maps,i,x;
+  register	tempNum,_maps,i,x;
   struct timeval    time;
   char          text[32];
-    
 
-  maps = nowDataRec.nowMap.mapNum;
+  _maps = nowDataRec.nowMap.mapNum;
 
-  if(nowMapFile->stageData[maps].minTime == 0)
+  if(nowMapFile->stageData[_maps].minTime == 0)
     {
       /**  not yet clear map  **/
       drawShadowText(display,mWin,120,300,
@@ -812,15 +811,15 @@
 
       x = 120;
       drawShadowText(display,mWin,x,300,
-		     nowMapFile->stageData[maps].minTimeName,white.pixel);
+		     nowMapFile->stageData[_maps].minTimeName,white.pixel);
 
-      x += XTextWidth(xfont,nowMapFile->stageData[maps].minTimeName,
-		      strlen(nowMapFile->stageData[maps].minTimeName));
+      x += XTextWidth(xfont,nowMapFile->stageData[_maps].minTimeName,
+		      strlen(nowMapFile->stageData[_maps].minTimeName));
       drawShadowText(display,mWin,x,300,
 		     " has the fastest time.",white.pixel);
 
 	
-      long2time(nowMapFile->stageData[maps].minTime,&time);
+      long2time(nowMapFile->stageData[_maps].minTime,&time);
 
       x = 250;
       sprintf(text,"%d",time.tv_sec);
