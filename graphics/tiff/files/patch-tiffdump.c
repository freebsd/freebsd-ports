--- tools/tiffdump.c.orig	2004-09-03 12:16:01 +0400
+++ tools/tiffdump.c	2004-12-22 01:57:51 +0300
@@ -307,6 +307,11 @@ ReadDirectory(int fd, unsigned ix, off_t
 			continue;
 		}
 		space = dp->tdir_count * datawidth[dp->tdir_type];
+		if (space <= 0) {
+			printf(">\n");
+			Error("Invalid count for tag %u", dp->tdir_tag);
+			continue;
+		}
 		if (space <= 4) {
 			switch (dp->tdir_type) {
 			case TIFF_FLOAT:
