--- pager.c.orig	2016-10-09 03:35:50.000000000 +0800
+++ pager.c	2016-12-02 11:21:36.940396000 +0800
@@ -20,6 +20,10 @@
 # include "config.h"
 #endif
 
+/*
+ * Trad. Chinese support by Michael Hsin <mhsin@mhsin.org>
+ */
+
 #include "mutt.h"
 #include "mutt_curses.h"
 #include "mutt_regex.h"
@@ -1101,7 +1105,7 @@ static int format_line (struct line_t **
   int space = -1; /* index of the last space or TAB */
   int col = option (OPTMARKERS) ? (*lineInfo)[n].continuation : 0;
   size_t k;
-  int ch, vch, last_special = -1, special = 0, t;
+  int ch, vch, last_special = -1, special = 0, t = 0, old_t = 0;
   wchar_t wc;
   mbstate_t mbstate;
   int wrap_cols = mutt_window_wrap_cols (pager_window, (flags & MUTT_PAGER_NOWRAP) ? 0 : Wrap);
@@ -1223,7 +1227,10 @@ static int format_line (struct line_t **
 	 * attempt to wrap at this character. */
 	wc = ' ';
       }
+      old_t = t;
       t = wcwidth (wc);
+      if (t > 1 || old_t > 1)
+        space = ch;
       if (col + t > wrap_cols)
 	break;
       col += t;
@@ -1447,6 +1454,7 @@ display_line (FILE *f, LOFF_T *last_pos,
       {
 	buf_ptr = buf + ch;
 	/* skip trailing blanks */
+        ch--;
 	while (ch && (buf[ch] == ' ' || buf[ch] == '\t' || buf[ch] == '\r'))
 	  ch--;
         /* a very long word with leading spaces causes infinite wrapping */
