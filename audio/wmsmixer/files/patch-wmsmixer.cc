--- wmsmixer.cc.orig	Tue Mar  6 07:39:43 2001
+++ wmsmixer.cc	Sat Nov 16 14:22:26 2002
@@ -547,7 +547,7 @@
   }
 }
 
-void checkVol(bool forced=true)
+void checkVol(bool forced)
 {
   mixctl->readVol(channel[curchannel], true);
   int nl=mixctl->readLeft(channel[curchannel]);
