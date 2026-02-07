--- status.c.orig
+++ status.c
@@ -8,7 +8,7 @@
  * score, the fruit level, and the number of lives remaining.
  */
 
-print_score(incr)
+void print_score(incr)
 long incr;
 {
    static char          string[6];
@@ -48,7 +48,7 @@
 }
 
 
-display_level(slowly)
+void display_level(slowly)
 Bool slowly;
 {
    int i, xx;
@@ -73,14 +73,14 @@
 }
 
 
-display_title()
+void display_title()
 {
    XCopyPlane(display, title, window, fullcopyGC, 0, 0, TITLE_WIDTH,
       TITLE_HEIGHT, 12 * GHOST_SIZE, WIN_HEIGHT + 1, 1);
 }
 
 
-restore_status()
+void restore_status()
 {
    print_score(0L);
    (void)set_lives(lives);
