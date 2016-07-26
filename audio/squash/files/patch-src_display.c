--- src/display.c.orig	2003-12-07 21:20:41 UTC
+++ src/display.c
@@ -179,6 +179,22 @@ void *display_monitor( void *input_data 
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
@@ -1567,7 +1583,7 @@ void draw_info( void ) {
     }
 
     /* Clip filename */
-    filename = strndup( filename, win_width - 2 );
+    filename = mystrndup( filename, win_width - 2 );
 
     /* Display filename and songs loaded */
     mvwprintw( win, 1, 1, "Current Selected Song filename:" );
