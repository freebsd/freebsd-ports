
$FreeBSD$

--- src/i_video.c	2003/02/10 15:10:49	1.1
+++ src/i_video.c	2003/02/10 15:11:08
@@ -54,7 +54,8 @@
 }
 
 void I_ShutdownGraphics(void) {
-  SW_ShutdownGraphics();
+  if (SW_ShutdownGraphics)
+    SW_ShutdownGraphics();
 }
 
 void I_StartTic(void) {
