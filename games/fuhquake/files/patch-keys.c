--- keys.c.orig	Mon Jun  2 22:41:44 2003
+++ keys.c	Mon Jun  2 22:41:52 2003
@@ -139,6 +139,13 @@
 	{"HOME", K_HOME},
 	{"END", K_END},
 
+	// Windows(tm) keys
+
+	{"K_WINDOW", K_WINDOW},
+	{"K_LWINDOW", K_LWINDOW},
+	{"K_RWINDOW", K_RWINDOW},
+	{"K_POPUPMENU", K_POPUPMENU},
+
 	{"MOUSE1", K_MOUSE1},
 	{"MOUSE2", K_MOUSE2},
 	{"MOUSE3", K_MOUSE3},
@@ -969,7 +976,7 @@
 	if (b < 0 || b >= sizeof(keybindings))
 		return false;
 
-	return	(b == K_CTRL || b == K_ALT || b == K_SHIFT) &&
+	return	(b == K_CTRL || b == K_ALT || b == K_SHIFT || b == K_WINDOW) &&
 			(keybindings[b + 1] && keybindings[b + 2] && !strcmp(keybindings[b + 1], keybindings[b + 2]));
 }
 
@@ -1082,6 +1089,10 @@
 	consolekeys[K_SHIFT] = true;
 	consolekeys[K_LSHIFT] = true;
 	consolekeys[K_RSHIFT] = true;
+	consolekeys[K_WINDOW] = true;
+	consolekeys[K_LWINDOW] = true;
+	consolekeys[K_RWINDOW] = true;
+	consolekeys[K_POPUPMENU] = true;
 	consolekeys[K_MWHEELUP] = true;
 	consolekeys[K_MWHEELDOWN] = true;
 	consolekeys['`'] = false;
@@ -1143,6 +1154,8 @@
 		Key_Event (K_CTRL, down);
 	else if (key == K_LSHIFT || key == K_RSHIFT)
 		Key_Event (K_SHIFT, down);
+	else if (key == K_LWINDOW || key == K_RWINDOW)
+		Key_Event (K_WINDOW, down);
 
 	keydown[key] = down;
 
