$FreeBSD$

--- src/display.c~	Tue Jul 29 06:56:49 2003
+++ src/display.c	Tue Aug  5 11:59:03 2003
@@ -673,6 +673,22 @@
     wrefresh( win );
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
  * Draw the info window.
  */
@@ -744,7 +760,7 @@
     }
 
     /* Clip filename */
-    filename = strndup( filename, win_width - 2 );
+    filename = mystrndup( filename, win_width - 2 );
 
     /* Display filename and songs loaded */
     mvwprintw( win, 1, 1, "Current Selected Song filename:" );
