--- reallyslick/c_src/driver.c.orig	Sun Feb 26 07:16:15 2006
+++ reallyslick/c_src/driver.c	Fri Apr 28 09:39:38 2006
@@ -152,10 +152,14 @@
 {
 	int bFPS = False;
 	XEvent event;
-	Atom XA_WM_PROTOCOLS = XInternAtom (XStuff->display, "WM_PROTOCOLS", False);
-	Atom XA_WM_DELETE_WINDOW = XInternAtom (XStuff->display, "WM_DELETE_WINDOW", False);
+	Atom XA_WM_PROTOCOLS;
+	Atom XA_WM_DELETE_WINDOW;
 	struct timeval then, now, fps_time;
 	int fps = 0;
+	int frameTimeSoFar = 0;
+
+	XA_WM_PROTOCOLS = XInternAtom (XStuff->display, "WM_PROTOCOLS", False);
+	XA_WM_DELETE_WINDOW = XInternAtom (XStuff->display, "WM_DELETE_WINDOW", False);
 
 	if (!rootWindow) {
 		XSetWMProtocols (XStuff->display, XStuff->window, &XA_WM_DELETE_WINDOW, 1);
@@ -164,7 +168,6 @@
 	clearBuffers();
 
 	gettimeofday (&now, NULL);
-	int frameTimeSoFar = 0;
 	while (!signalled) {
 		hack_draw (XStuff, (double)now.tv_sec + now.tv_usec / 1000000.0f, frameTimeSoFar / 1000000.0f);
 
