--- ball/game.c.orig	Sun Apr 18 16:18:16 2004
+++ ball/game.c	Sun Apr 18 16:18:31 2004
@@ -127,7 +127,7 @@
 
 char *curr_intro(void)
 {
-    return file.av;
+    return (file.ac > 0) ? file.av : NULL;
 }
 
 /*---------------------------------------------------------------------------*/
