--- src/page.c.orig	Wed Feb 21 03:18:52 2001
+++ src/page.c	Thu Apr 19 09:35:25 2001
@@ -867,7 +867,7 @@
 		curr = &artline[curr_line+i];
 		fseek (note_fp, curr->offset, SEEK_SET);
 
-		fgets (buff, cCOLS+1, note_fp);
+		fgets (buff, MAXPATHLEN, note_fp);
 
 		/*
 		 * rotN encoding on body and sig data only
@@ -1186,7 +1186,7 @@
 
 		make_group_path (CURR_GROUP.name, group_path);
 
-		switch (art_open (TRUE, &arts[new_respnum], group_path, &pgart)) {
+		switch (art_open (FALSE, &arts[new_respnum], group_path, &pgart)) {
 
 			case ART_UNAVAILABLE:
 				art_mark_read (&CURR_GROUP, &arts[new_respnum]);
