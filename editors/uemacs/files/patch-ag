--- src/unix.c.orig	Sat Nov 13 14:57:12 1999
+++ src/unix.c	Sat Nov 13 15:04:45 1999
@@ -816,9 +816,19 @@
 		exit(1);
 	}
 
-	/* Get size from termcap */
-	term.t_nrow = tgetnum("li") - 1;
-	term.t_ncol = tgetnum("co");
+	/*
+	 * If LINES and/or COLUMNS are set in the environment then use those
+	 * values, otherwise get them from termcap.
+	 */
+	if ((cp = getenv("LINES")) == NULL || sscanf(cp, "%d",
+	    &term.t_nrow) != 1)
+		term.t_nrow = tgetnum("li");
+	term.t_nrow -= 1;
+
+	if ((cp = getenv("COLUMNS")) == NULL || sscanf(cp, "%d",
+	    &term.t_ncol) != 1)
+		term.t_ncol = tgetnum("co");
+
 	if (term.t_nrow < 3 || term.t_ncol < 3) {
 		puts("Screen size is too small!");
 		exit(1);
