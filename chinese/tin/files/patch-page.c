--- src/page.c.orig	Wed Feb 21 03:18:52 2001
+++ src/page.c	Mon Apr 30 03:28:06 2001
@@ -844,7 +844,7 @@
 
 	search_line = curr_line;	/* Reset search to start from top of display */
 
-	buff = my_malloc(cCOLS+1);	/* Need to account for \n */
+	buff = my_malloc(LEN+1);	/* Need to account for \n */
 
 	if (part == 0) {
 		ClearScreen();
@@ -867,7 +867,7 @@
 		curr = &artline[curr_line+i];
 		fseek (note_fp, curr->offset, SEEK_SET);
 
-		fgets (buff, cCOLS+1, note_fp);
+		fgets (buff, LEN+1, note_fp);
 
 		/*
 		 * rotN encoding on body and sig data only
@@ -886,7 +886,7 @@
 		strip_line(buff);
 
 #ifndef USE_CURSES
-		snprintf (screen[i+PAGE_HEADER].col, cCOLS, "%s" cCRLF, buff);
+		snprintf (screen[i+PAGE_HEADER].col, LEN, "%s" cCRLF, buff);
 #endif /* !USE_CURSES */
 
 		MoveCursor (i+PAGE_HEADER, 0);
@@ -1346,7 +1346,7 @@
 					chunk += 50;
 					pgart.rawl = my_realloc((char *)pgart.rawl, sizeof(t_lineinfo) * chunk);
 				}
-			} while ((fgets(buff, cCOLS+1, pgart.raw)) != NULL);
+			} while ((fgets(buff, LEN+1, pgart.raw)) != NULL);
 
 			j--;
 			pgart.rawl = my_realloc((char *)pgart.rawl, sizeof(t_lineinfo) * j);
