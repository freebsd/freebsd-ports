--- src/page.c.orig	Sat Apr 27 23:04:47 2002
+++ src/page.c	Sun May 26 13:35:27 2002
@@ -952,8 +952,8 @@
 		if ((line = tin_fgets (file, FALSE)) == NULL)
 			break;	/* ran out of message */
 
-		if ((int) strlen(line) >= cCOLS)
-			line[cCOLS] = '\0';
+		if ((int) strlen(line) >= LEN)
+			line[LEN] = '\0';
 
 		/*
 		 * rotN encoding on body and sig data only
@@ -971,7 +971,7 @@
 		strip_line(line);
 
 #ifndef USE_CURSES
-		snprintf (screen[i + scroll_region_top].col, cCOLS, "%s" cCRLF, line);
+		snprintf (screen[i + scroll_region_top].col, LEN, "%s" cCRLF, line);
 #endif /* !USE_CURSES */
 
 		MoveCursor (i + scroll_region_top, 0);
@@ -1492,7 +1492,7 @@
 					chunk += 50;
 					pgart.rawl = my_realloc((char *) pgart.rawl, sizeof(t_lineinfo) * chunk);
 				}
-			} while ((fgets(buff, cCOLS + 1, pgart.raw)) != NULL);
+			} while ((fgets(buff, LEN + 1, pgart.raw)) != NULL);
 
 			j--;
 			pgart.rawl = my_realloc((char *) pgart.rawl, sizeof(t_lineinfo) * j);
