--- wmsmixer.cc.orig	2003-04-12 22:08:58 UTC
+++ wmsmixer.cc
@@ -547,7 +547,7 @@ void readFile()
   }
 }
 
-void checkVol(bool forced=true)
+void checkVol(bool forced)
 {
   mixctl->readVol(channel[curchannel], true);
   int nl=mixctl->readLeft(channel[curchannel]);
