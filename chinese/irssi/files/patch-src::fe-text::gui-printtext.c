--- src/fe-text/gui-printtext.c.orig	Mon Dec 30 00:10:02 2002
+++ src/fe-text/gui-printtext.c	Sun Dec 14 01:54:28 2003
@@ -255,7 +255,7 @@
 		if (flags & GUI_PRINT_FLAG_CLRTOEOL)
 			term_clrtoeol(root_window);
 		term_addstr(root_window, str);
-		next_xpos += strlen(str);
+		next_xpos += strlen(str); // FIXME utf8 or big5
                 return;
 	}
 
