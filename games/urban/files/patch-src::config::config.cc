--- src/config/config.cc.orig	Sun Jun  6 15:37:17 1999
+++ src/config/config.cc	Sun Jan 25 23:34:40 2004
@@ -91,10 +91,10 @@
 	/* Ask for the number of buttons */
 
         fnt.print_centre("Gamepad type:", 160, 100);
-	fnt.print_centre("  1. 2 buttons
-  2. 4 buttons
-  3. 6 buttons
-  4. 8 buttons", 160, 140);
+	fnt.print_centre("  1. 2 buttons"
+"  2. 4 buttons"
+"  3. 6 buttons"
+"  4. 8 buttons", 160, 140);
 	int running = 1;
 
 	while(running) {
