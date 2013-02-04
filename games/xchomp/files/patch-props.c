--- props.c.orig
+++ props.c
@@ -9,7 +9,7 @@
 
 
 /* the get-ready sequence */
-get_ready()
+void get_ready()
 {
    int          xx, yy, i;
    int          direction, ascent, descent;
@@ -41,7 +41,7 @@
 
 
 /* the game-over sequence */
-game_over()
+void game_over()
 {
    int          xx, yy;
    int          direction, ascent, descent;
@@ -64,7 +64,7 @@
 
 
 /* the end-of-level sequence -- the screen flashes a few times */
-finish()
+void finish()
 {
    int i;
 
@@ -115,7 +115,7 @@
       if (event.xany.window != window) continue;
       switch (event.type) {
 	 case KeyPress:
-	    XLookupString(&event, &c_buf, 1, &last_key, &status);
+	    XLookupString((XKeyEvent *) &event, &c_buf, 1, &last_key, &status);
 	    if ((last_key == XK_q) || (last_key == XK_Q))
 	       do_exit();
 	    if ((last_key == XK_r) || (last_key == XK_R))
@@ -136,7 +136,7 @@
 }
 
 
-do_sleep(secs)
+void do_sleep(secs)
 {
    int i;
 
@@ -147,7 +147,7 @@
 }
 
 
-do_usleep(usecs)
+void do_usleep(usecs)
 {
    int i, d, r;
 
@@ -164,7 +164,7 @@
 }
 
 
-check_normal_events()
+void check_normal_events()
 {
    char			c_buf;
    XEvent		event;
@@ -175,7 +175,7 @@
       if (event.xany.window != window) continue;
       switch (event.type) {
          case KeyPress:
-            XLookupString(&event, &c_buf, 1, &last_key, &status);
+            XLookupString((XKeyEvent *) &event, &c_buf, 1, &last_key, &status);
             if (last_key == XK_space)
                if (!pause_seq())
                   longjmp(jb_start, 1);
