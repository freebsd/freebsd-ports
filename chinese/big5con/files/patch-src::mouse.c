--- src/mouse.c.orig	Sun Apr 14 16:40:40 1996
+++ src/mouse.c	Tue Nov 26 11:41:05 2002
@@ -167,7 +167,8 @@
 
 	mouseType = MOUSE_NONE;
 	mInfo.has_mouse = FALSE;
-	sscanf(config, "%s", name);
+	strncpy(name, config, MAX_COLS - 1);
+	name[MAX_COLS - 1] = '\0';
 	for (p = mice; p->name != NULL; p++) {
 		if (strcasecmp(name, p->name) == 0) {
 			mouseType = p->type;
