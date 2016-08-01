--- cfg.c.orig	1997-06-11 12:05:34 UTC
+++ cfg.c
@@ -203,7 +203,7 @@ cfg_read (char *fname, void *bp, char *s
 			fcur -> fp = fp;
 			fcur -> up = NULL;
 			while (fcur) {
-				while (gline = getline (fcur -> fp, True)) {
+				while (gline = get_line (fcur -> fp, True)) {
 					for (line = gline; isspace (*line); ++line)
 						;
 					if ((! *line) || (*line == '#')) {
@@ -279,7 +279,7 @@ cfg_read (char *fname, void *bp, char *s
 								done = False;
 								siz = 0;
 								len = 0;
-								while (ptr = getline (fcur -> fp, False)) {
+								while (ptr = get_line (fcur -> fp, False)) {
 									if ((*ptr != '}') || *(ptr + 1)) {
 										plen = strlen (ptr);
 										if (len + plen + 2 >= siz) {
