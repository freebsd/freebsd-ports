--- src/keyboard.c.orig	Sun Aug 15 19:13:01 2004
+++ src/keyboard.c	Sun Aug 15 19:13:31 2004
@@ -24,7 +24,6 @@
 #define INC (x0 += KEY_WIDTH)
 #define HALFINC (x0 += KEY_WIDTH/2)
 
-extern int ForwardEvent();
 static void set_key(int n, unsigned long keysym, int x, int y, int w, int h);
 static int in_keys(int x0, int y0);
 
