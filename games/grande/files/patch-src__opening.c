--- src/opening.c.orig	Sun Oct  9 08:54:01 2005
+++ src/opening.c	Sun Oct  9 08:54:12 2005
@@ -190,6 +190,7 @@
     KXL_PutText(CENTER(menubuff[i]), UP_TOP + 140 + i * 16, menubuff[i]);
   }
 
+/*
   if (JoyConfig.buttons) {
     if (sel == 0)
       JoyMainShot = JoyConfig.buttons;
@@ -202,6 +203,7 @@
     else if (sel == 4)
       JoyExit = JoyConfig.buttons;
   }
+*/
   // ¥­¡¼È½Äê
   if (OldKey != Root->Key) {
     if (OldKey == KNone && Root->Key) {
