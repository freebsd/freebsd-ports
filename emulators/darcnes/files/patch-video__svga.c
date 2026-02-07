--- video_svga.c.orig	2000-09-16 23:45:10 UTC
+++ video_svga.c
@@ -52,7 +52,6 @@ unsigned char *vbpfunc8(int line);
 
 void video_events(void);
 
-__inline__
 void input_update()
 {
     keyboard_update();
