--- src/page.c.orig	Mon Jul 23 18:14:53 2001
+++ src/page.c	Wed Aug  8 18:24:04 2001
@@ -838,8 +838,8 @@
 		fseek (file, curr->offset, SEEK_SET);
 		if ((line = tin_fgets (file, FALSE)) == NULL)
 			break;	/* ran out of message */
-		if ((int) strlen(line) >= cCOLS)
-			line[cCOLS] = '\0';
+		if ((int) strlen(line) >= LEN)
+			line[LEN] = '\0';
 
 		/*
 		 * rotN encoding on body and sig data only
@@ -858,7 +858,7 @@
 		strip_line(line);
 
 #ifndef USE_CURSES
-		snprintf (screen[i + scroll_region_top].col, cCOLS, "%s" cCRLF, line);
+		snprintf (screen[i + scroll_region_top].col, LEN, "%s" cCRLF, line);
 #endif /* !USE_CURSES */
 
 		MoveCursor (i + scroll_region_top, 0);
@@ -1364,7 +1364,7 @@
 					chunk += 50;
 					pgart.rawl = my_realloc((char *) pgart.rawl, sizeof(t_lineinfo) * chunk);
 				}
-			} while ((fgets(buff, cCOLS + 1, pgart.raw)) != NULL);
+			} while ((fgets(buff, LEN + 1, pgart.raw)) != NULL);
 
 			j--;
 			pgart.rawl = my_realloc((char *) pgart.rawl, sizeof(t_lineinfo) * j);
