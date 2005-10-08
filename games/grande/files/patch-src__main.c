--- src/main.c.orig	Sun Oct  9 08:43:56 2005
+++ src/main.c	Sun Oct  9 08:53:37 2005
@@ -77,13 +77,14 @@
 void MainLoop(void)
 {
   MainEnum bak = -1;
-  KXL_Joystick jsev, jsbak;
+//  KXL_Joystick jsev, jsbak;
 
   while (1) {
     // タイマ割込み待ち
     while (KXL_GetTimer() == False);
     // タイマ割込みリスタート
     KXL_ResetTimer();
+/*
     // joystick
     if (gJoyok == True) {
       if (KXL_ReadJoystick(&jsev) == False)
@@ -120,6 +121,7 @@
 	}
       }
     }
+*/
 
     // イベントチェック
     while (KXL_CheckEvents()) {
