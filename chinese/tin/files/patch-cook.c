--- src/cook.c.orig	Mon Feb 19 22:59:13 2001
+++ src/cook.c	Mon Apr 30 02:57:21 2001
@@ -109,7 +109,7 @@
 			while (i++ < j)
 				*q++ = ' ';
 
-		} else if (((*p) & 0xFF) < ' ' && *p != '\n') {	/* Literal ctrl chars */
+		} else if (((*p) & 0xFF) < ' ' && *p != '\n' && *p != 27) {	/* Literal ctrl chars */
 			*q++ = '^';
 			*q++ = ((*p) & 0xFF) + '@';
 			if (*p == '\f')					/* ^L detected */
@@ -147,6 +147,7 @@
 	vsnprintf (buf, sizeof(buf) - 1, fmt, ap);
 
 	bufp = buf;
+	wrap_lines = FALSE;
 
 	for (p = bufp; *p; p++) {
 		if (*p == '\n' || ((overflow + p - bufp >= cCOLS) && wrap_lines)) {
