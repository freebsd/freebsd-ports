--- src/display.c.orig	2003-12-07 21:20:41 UTC
+++ src/display.c
@@ -179,6 +179,22 @@ void *display_monitor( void *input_data ) {
     return (void *)NULL;
 }
 
+char *mystrndup(const char *s, size_t sz)
+{
+    size_t l = strlen(s), i;
+    char *x;
+
+    i = l < sz ? l : sz;
+
+    x = malloc(i + 1);
+
+    if (x) {
+	memcpy(x, s, i);
+	x[i] = '\0';
+    }
+    return x;
+}
+
 /*
  * Draw the screen,  This takes into account rebuilding all the
  * windows in case of screen resize, or if a window changes size.
@@ -1164,9 +1180,7 @@ void draw_now_playing( void ) {
         /* Print Time Information */
         mvwprintw(    win, 3, time_left, "%d:%02d",
             (int)(cur_position / 60),
-            (int)(cur_position % 60),
-            (int)(cur_duration / 60),
-            (int)(cur_duration % 60) );
+            (int)(cur_position % 60) );
     } else {
         /* Print Time Information */
         mvwprintw(    win, 3, time_left, "%d:%02d/%d:%02d",
@@ -1247,7 +1261,7 @@ void draw_list( int which_window ) {
     mvwaddch( win, 1, win_width - 1, ACS_RTEE );
 
     /* Print Headers */
-    mvwprintw( win, 0, 2, header );
+    mvwprintw( win, 0, 2, "%s", header );
     mvwaddstr( win, 1, col_left[0], "Artist" );
     mvwaddstr( win, 1, col_left[1], "Title" );
     mvwaddstr( win, 1, col_left[2], "Album" );
@@ -1457,7 +1471,7 @@ void draw_help( void ) {
     /* Get window size */
     getmaxyx( win, win_height, win_width );
 
-    mvwprintw( win, 2, win_width - strlen(version) - 1, version );
+    mvwprintw( win, 2, win_width - strlen(version) - 1, "%s", version );
 
     /* Print Text */
     mvwaddstr( win, 0 , 2, "Quit" );
@@ -1567,11 +1581,11 @@ void draw_info( void ) {
     }
 
     /* Clip filename */
-    filename = strndup( filename, win_width - 2 );
+    filename = mystrndup( filename, win_width - 2 );
 
     /* Display filename and songs loaded */
     mvwprintw( win, 1, 1, "Current Selected Song filename:" );
-    mvwprintw( win, 2, 1, "%s", filename );
+    mvwprintw( win, 2, 1, "%s", filename ? filename : "" );
     mvwprintw( win, 3, 1, "Songs loaded: %d", database_info.song_count );
 
     /* Free filename */
@@ -1651,7 +1665,7 @@ void draw_meta_string( WINDOW *win, song_info_t *song,
     }
 
     /* Print the line */
-    mvwprintw( win, top, left, line_buffer );
+    mvwprintw( win, top, left, "%s", line_buffer );
 
     /* Cleanup */
     squash_free( line_buffer );
