--- lib/system.cc.orig	Sun Nov 25 01:43:10 2001
+++ lib/system.cc	Sun Nov 25 01:44:49 2001
@@ -857,13 +857,18 @@
 {
 	TEvent event;
 	mouse_info_t mi;
+	int heightDivider = 16;
 
 	mi.operation = MOUSE_GETINFO;
 	ioctl(STDOUT_FILENO, CONS_MOUSECTL, &mi);
+
+	if (TScreen::screenHeight > 25)
+		heightDivider = 8;
+
 	event.mouse.controlKeyState = kbReadShiftState();
 	event.mouse.where.x = range(mi.u.data.x / 8, 0,
 		TScreen::screenWidth - 1);
-	event.mouse.where.y = range(mi.u.data.y / 16, 0,
+	event.mouse.where.y = range(mi.u.data.y / heightDivider, 0,
 		TScreen::screenHeight - 1);
 
 	/* convert button bits to TV standard */
