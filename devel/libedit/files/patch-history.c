--- history.c.orig	Tue Nov 23 01:41:41 2004
+++ history.c	Tue Nov 23 01:43:09 2004
@@ -728,10 +728,10 @@
 	for (i = 0, retval = HLAST(h, &ev);
 	    retval != -1;
 	    retval = HPREV(h, &ev), i++) {
-		len = strlen(ev.str) * 4;
-		if (len >= max_size) {
+		len = strlen(ev.str) * 4 + 1;
+		if (len > max_size) {
 			char *nptr;
-			max_size = (len + 1023) & 1023;
+			max_size = (len + 1023) & ~1023;
 			nptr = h_realloc(ptr, max_size);
 			if (nptr == NULL) {
 				i = -1;
