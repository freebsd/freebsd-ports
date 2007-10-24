--- gok/main.c.orig	2007-10-13 16:43:20.000000000 -0400
+++ gok/main.c	2007-10-13 16:47:05.000000000 -0400
@@ -1229,6 +1229,7 @@ static gboolean gok_main_xevie_io (GIOCh
 {
 #ifdef HAVE_XEVIE
     while (xevie_dpy && XPending (xevie_dpy)) {
+      XEvent xevie_event;
       XMotionEvent *motion_event;
       gboolean has_active_key = gok_scanner_key_is_active ();
       /* Xevie has a motion event for us to check */
