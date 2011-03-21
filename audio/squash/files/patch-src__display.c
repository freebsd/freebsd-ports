--- ./src/display.c.orig	2003-12-07 22:20:41.000000000 +0100
+++ ./src/display.c	2011-03-21 17:21:19.000000000 +0100
@@ -179,6 +179,22 @@
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
@@ -1567,7 +1583,7 @@
     }
 
     /* Clip filename */
-    filename = strndup( filename, win_width - 2 );
+    filename = mystrndup( filename, win_width - 2 );
 
     /* Display filename and songs loaded */
     mvwprintw( win, 1, 1, "Current Selected Song filename:" );
