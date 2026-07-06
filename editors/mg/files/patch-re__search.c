--- re_search.c.orig	2026-05-20 10:30:42 UTC
+++ re_search.c
@@ -146,6 +146,10 @@ re_queryrepl(int f, int n)
		return (ABORT);
	ewprintf("Query replacing %s with %s:", re_pat, news);

+	/* If dot on empty line, suppress line forward in re_forwsrch */
+	if (curwp->w_doto == 0 && curwp->w_dotp->l_used == 0)
+		curwp->w_doto = -1;
+
	/*
	 * Search forward repeatedly, checking each time whether to insert
	 * or not.  The "!" case makes the check always true, so it gets put
@@ -222,6 +226,9 @@ re_repl(int f, int n)
	    EFNUL | EFNEW | EFCR, re_pat) == NULL)
                 return (ABORT);

+	/* If dot on empty line, suppress line forward in re_forwsrch */
+	if (curwp->w_doto == 0 && curwp->w_dotp->l_used == 0)
+		curwp->w_doto = -1;
	while (re_forwsrch() == TRUE) {
		plen = regex_match[0].rm_eo - regex_match[0].rm_so;
		if (re_doreplace((RSIZE)plen, news) == FALSE)
@@ -353,6 +360,9 @@ re_forwsrch(void)
			tdotline++;
			tbo = 0;
		}
+	if (tbo < 0)
+		/* line forward was suppressed */
+		tbo = 0;
	/*
	 * Note this loop does not process the last line, but this editor
	 * always makes the last line empty so this is good.
