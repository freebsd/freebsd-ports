--- vi/vs_refresh.c.orig	2023-09-25 08:47:42 UTC
+++ vi/vs_refresh.c
@@ -774,7 +774,8 @@ vs_modeline(SCR *sp)
 	size_t cols, curcol, curlen, endpoint, len, midpoint;
 	const char *t = NULL;
 	int ellipsis;
-	char buf[20];
+	char buf[30];
+	recno_t last;
 
 	gp = sp->gp;
 
@@ -795,7 +796,7 @@ vs_modeline(SCR *sp)
 
 	/* If more than one screen in the display, show the file name. */
 	curlen = 0;
-	if (IS_SPLIT(sp)) {
+	if (IS_SPLIT(sp) || O_ISSET(sp, O_SHOWFILENAME)) {
 		CHAR_T *wp, *p;
 		size_t l;
 
@@ -846,8 +847,14 @@ vs_modeline(SCR *sp)
 	cols = sp->cols - 1;
 	if (O_ISSET(sp, O_RULER)) {
 		vs_column(sp, &curcol);
-		len = snprintf(buf, sizeof(buf), "%lu,%lu",
-		    (u_long)sp->lno, (u_long)(curcol + 1));
+
+		if (db_last(sp, &last) || last == 0)
+			len = snprintf(buf, sizeof(buf), "%lu,%zu",
+			    (u_long)sp->lno, curcol + 1);
+		else
+			len = snprintf(buf, sizeof(buf), "%lu,%zu %lu%%",
+			    (u_long)sp->lno, curcol + 1,
+			    (u_long)(sp->lno * 100) / last);
 
 		midpoint = (cols - ((len + 1) / 2)) / 2;
 		if (curlen < midpoint) {
