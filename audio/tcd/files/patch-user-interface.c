--- src/user-interface.c.orig	2008-06-27 22:55:46.000000000 +0200
+++ src/user-interface.c	2008-06-27 22:55:49.000000000 +0200
@@ -186,8 +186,10 @@
     phelp(3, 26, 'G', "- Go to track", playable);
     phelp(4, 26, ']', "- Skip ahead", playable);
     phelp(5, 26, '[', "- Skip back", playable);
-    phelp(7, 1, 'T', "- Edit track database", playable);
-    phelp(8, 1, 'Q', "- Quit", 1);
+    phelp(7, 1, '*', "- Increase volume", playable);
+    phelp(8, 1, '/', "- Decrease volume", playable);
+    phelp(10, 1, 'T', "- Edit track database", playable);
+    phelp(11, 1, 'Q', "- Quit", 1);
 }
 
 static void draw_info(struct tcd_state *state)
