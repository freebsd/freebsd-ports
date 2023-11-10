--- src/video/x11.c.orig	2023-10-08 02:12:37 UTC
+++ src/video/x11.c
@@ -53,6 +53,16 @@ static int pipefd[2];
 static int display_width;
 static int display_height;
 
+static void resetcursor() {
+  XColor dummy;
+  Cursor cursor;
+  const char data[1] = {0};
+  Pixmap blank = XCreateBitmapFromData(display, window, data, 1, 1);
+  cursor = XCreatePixmapCursor(display, blank, blank, &dummy, &dummy, 0, 0);
+  XFreePixmap(display, blank);
+  XDefineCursor(display, window, cursor);
+}
+
 static int frame_handle(int pipefd) {
   AVFrame* frame = NULL;
   while (read(pipefd, &frame, sizeof(void*)) > 0);
@@ -75,7 +85,7 @@ int x11_init(bool vdpau, bool vaapi) {
     return 0;
 
   #ifdef HAVE_VAAPI
-  if (vaapi && vaapi_init_lib(display) == 0)
+  if (vaapi && vaapi_init_lib() == 0)
     return INIT_VAAPI;
   #endif
 
@@ -100,10 +110,12 @@ int x11_setup(int videoFormat, int width, int height, 
   }
 
   Window root = DefaultRootWindow(display);
-  XSetWindowAttributes winattr = { .event_mask = PointerMotionMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask | KeyReleaseMask };
+  XSetWindowAttributes winattr = { .event_mask = PointerMotionMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask | KeyReleaseMask | FocusChangeMask };
   window = XCreateWindow(display, root, 0, 0, display_width, display_height, 0, CopyFromParent, InputOutput, CopyFromParent, CWEventMask, &winattr);
   XMapWindow(display, window);
   XStoreName(display, window, "Moonlight");
+  // Fix the bug that the default cursor keep in screen when streaming.
+  resetcursor();
 
   if (drFlags & DISPLAY_FULLSCREEN) {
     Atom wm_state = XInternAtom(display, "_NET_WM_STATE", False);
