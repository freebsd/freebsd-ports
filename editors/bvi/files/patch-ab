--- io.c.orig	Tue Nov  2 04:44:10 1999
+++ io.c	Fri Nov 26 18:06:58 1999
@@ -119,7 +119,7 @@
 		} else if (S_ISBLK(buf.st_mode)) {
 			filemode = BLOCK_SPECIAL;
 		} else if (S_ISREG(buf.st_mode)) {
-			if ((unsigned long)buf.st_size > (unsigned long)SIZE_T_MAX) {
+			if (buf.st_size > SIZE_T_MAX) {
 				move(maxy, 0);
 				endwin();
 				printf("File too large\n");
