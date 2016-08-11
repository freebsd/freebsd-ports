--- src/user-interface.c.orig	2004-06-15 21:14:47 UTC
+++ src/user-interface.c
@@ -186,8 +186,10 @@ static void draw_control_panel(struct tc
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
