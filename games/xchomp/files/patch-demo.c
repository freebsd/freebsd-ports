--- demo.c.orig
+++ demo.c
@@ -6,7 +6,7 @@
  * for the game.
  */
 
-demo_seq()
+void demo_seq()
 {
    int             i, xx, yy, direction, ascent, descent, len;
    XCharStruct     chars;
@@ -127,7 +127,7 @@
       if (event.xany.window != window) continue;
       switch (event.type) {
          case KeyPress:
-	    XLookupString(&event, &c_buf, 1, &last_key, &status);
+	    XLookupString((XKeyEvent *) &event, &c_buf, 1, &last_key, &status);
 	    if ((last_key == XK_q) || (last_key == XK_Q))
 	       do_exit();
 	    XFillRectangle(display, window, clearGC, 0, 0, WIN_WIDTH,
