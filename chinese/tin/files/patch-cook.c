--- src/cook.c.orig	Sat Sep 23 14:34:20 2000
+++ src/cook.c	Sat Sep 23 14:34:41 2000
@@ -109,7 +109,7 @@
 			while (i++ < j)
 				*q++ = ' ';
 
-		} else if (((*p) & 0xFF) < ' ' && *p != '\n') {	/* Literal ctrl chars */
+		} else if (((*p) & 0xFF) < ' ' && *p != '\n' && *p != 27) {	/* Literal ctrl chars */
 			*q++ = '^';
 			*q++ = ((*p) & 0xFF) + '@';
 			if (*p == '\f')					/* ^L detected */
