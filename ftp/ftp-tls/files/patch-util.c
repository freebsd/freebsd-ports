--- util.c.orig	Fri Oct 25 14:17:24 2002
+++ util.c	Fri Oct 25 15:07:39 2002
@@ -1013,9 +1013,19 @@
 controlediting()
 {
 	if (editing && el == NULL && hist == NULL) {
+#ifdef ENHANCED_LIBEDIT
+		HistEvent ev;
+
+		el = el_init(progname, stdin, ttyout, stderr);	/* init editline */
+#else
 		el = el_init(progname, stdin, ttyout); /* init editline */
+#endif
 		hist = history_init();		/* init the builtin history */
+#ifndef ENHANCED_LIBEDIT
 		history(hist, H_EVENT, 100);	/* remember 100 events */
+#else
+		history(hist, &ev, H_SETSIZE, 100);	/* remember 100 events */
+#endif
 		el_set(el, EL_HIST, history, hist);	/* use history */
 
 		el_set(el, EL_EDITOR, "emacs");	/* default editor is emacs */
