--- src/server-term.c.orig	Sun Jun 17 04:47:01 2001
+++ src/server-term.c	Sun Aug 22 03:46:07 2004
@@ -348,6 +348,7 @@
 	jump2:
 		i++;
 	jump:
+		;
 	}
 	newtext[j] = 0;
 	zvt_term_feed (ZVT_TERM (widget), newtext, j);
