--- src/mouse.c.orig	1997-01-27 20:40:27.000000000 +0900
+++ src/mouse.c	2012-05-10 00:14:28.944551694 +0900
@@ -122,11 +122,11 @@
 		}
 };
 
-static int mouseBaud;
+static int mouseBaud = B1200;
 
 static int	ConfigMouseBaud(const char *config)
 {
-	int baud;
+	int baud = 0;
 
 	sscanf(config, "%d", &baud);
 
@@ -149,19 +149,23 @@
 	return SUCCESS;
 }
 
-static char *mouseDev;
+static char *mouseDev = NULL;
 
 static int	ConfigMouseDev(const char *config)
 {
-	char name[MAX_COLS];
-	sscanf(config, "%s", name);
+	char *name, *last, *sep = " \t\r\n";
 
-	if (mouseDev) free(mouseDev);
+	name = strtok_r((char *)config, sep, &last);
+	if (name == NULL) {
+		warn("unknown mouse type ignored; assuming no mouse\r\n");
+		return SUCCESS;
+	}
+	SafeFree(mouseDev);
 	mouseDev = strdup(name);
 	return SUCCESS;
 }
 
-static int	pasteButton;
+static int	pasteButton = MOUSE_RGT;
 
 static int      Config3Buttons(const char *config)
 { 
@@ -172,11 +176,15 @@
 static int	ConfigMouse(const char *config)
 {
 	struct mouseconf *p;
-	char name[MAX_COLS];
+	char *name, *last, *sep = " \t\r\n";
 
 	mouseType = MOUSE_NONE;
 	mInfo.has_mouse = FALSE;
-	sscanf(config, "%s", name);
+	name = strtok_r((char *)config, sep, &last);
+	if (name == NULL) {
+		warn("unknown mouse type ignored; assuming no mouse\r\n");
+		return SUCCESS;
+	}
 	for (p = mice; p->name != NULL; p++) {
 		if (strcasecmp(name, p->name) == 0) {
 			mouseType = p->type;
@@ -253,7 +261,7 @@
     if ((mfd = open(mouseDev, O_RDWR|O_NONBLOCK)) < 0) {
 	warn("couldn't open mouse device; mouse disabled\n");
 	Perror(mouseDev);
-	free(mouseDev);
+	SafeFree(mouseDev);
 	mouseDev = NULL;
 	mInfo.has_mouse = FALSE;
 	return -1;
