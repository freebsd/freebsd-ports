--- main.c.orig	Sun Oct 29 19:17:55 1995
+++ main.c	Tue Feb 18 19:11:56 1997
@@ -200,7 +200,7 @@
 	ansi_escapes = 0;
 	if ((cp = getenv("TERM")) != NULL) {
 		if ((*cp == 'v' && cp[1] == 't')		/* vt100, vt102, ... */
-			|| (strcmp(cp, "xterm") == 0))
+			|| (strncmp(cp, "xterm", 5) == 0))
 			ansi_escapes = 1;
 	}
 #endif
