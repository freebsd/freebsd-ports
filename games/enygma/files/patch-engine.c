--- engine.c.orig	Sun Sep 14 23:23:42 2008
+++ engine.c	Sun Sep 14 22:06:32 2008
@@ -181,7 +181,7 @@
      * process teleporters
      */
     if (i == '#') {
-	int x, y;
+	int x, y = 0;
 
 	/*
 	 * First find the other teleporter.
