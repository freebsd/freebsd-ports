--- re_search.c.orig	2024-04-06 09:29:51 UTC
+++ re_search.c
@@ -342,10 +342,9 @@ re_forwsrch(void)
 	if (tbo == clp->l_used)
 		/*
 		 * Don't start matching past end of line -- must move to
-		 * beginning of next line, unless line is empty or at
-		 * end of file.
+		 * beginning of next line, unless at end of file.
 		 */
-		if (clp != curbp->b_headp && llength(clp) != 0) {
+		if (clp != curbp->b_headp) {
 			clp = lforw(clp);
 			tdotline++;
 			tbo = 0;
