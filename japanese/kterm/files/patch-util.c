--- util.c.orig	2016-11-04 21:41:21 UTC
+++ util.c
@@ -36,6 +36,7 @@
 
 #include <stdio.h>
 
+static void ClearInLine(TScreen *screen, int row, int col, int len);
 static void horizontal_copy_area();
 static void vertical_copy_area();
 
@@ -706,6 +707,54 @@ register TScreen *screen;
 /* 
  * Clear last part of cursor's line, inclusive.
  */
+ClearRightN (screen, n)
+register TScreen *screen;
+register int     n;
+{
+        int i;
+	int len = (screen->max_col - screen->cur_col + 1);
+
+	if (n < 0)      /* the remainder of the line */
+		n = screen->max_col + 1;
+	if (n == 0)     /* default for 'ECH' */
+		n = 1;
+
+	if (len > n)
+		len = n;
+
+        ClearInLine(screen, screen->cur_row, screen->cur_col, len);
+}
+
+/*
+ * Clear the given row, for the given range of columns.
+ */
+static void
+ClearInLine(TScreen *screen, int row, int col, int len)
+{
+	if (col + len >= screen->max_col + 1) {
+		len = screen->max_col + 1 - col;
+	}
+
+	if (screen->cursor_state)
+		HideCursor();
+
+	screen->do_wrap = 0;
+
+	if (row - screen->topline <= screen->max_row) {
+		if (!AddToRefresh(screen)) {
+			if (screen->scroll_amt)
+				FlushScroll(screen);
+			XClearArea(screen->display,
+				VWindow(screen),
+				CursorX (screen, col),
+				CursorY (screen, row),
+                                len * FontWidth(screen),
+                                FontHeight(screen),
+				FALSE);
+                }
+        }
+}
+
 ClearRight (screen)
 register TScreen *screen;
 {
