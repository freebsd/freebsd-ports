--- uip/vmh.c.old	Tue Feb  9 20:30:00 1999
+++ uip/vmh.c	Wed Jul 10 15:40:52 2002
@@ -103,6 +103,16 @@
 
 #define	XYZ			/* XXX */
 
+#if defined(__FreeBSD__) && __FreeBSD__ >= 5
+struct ldat
+{
+	NCURSES_CH_T	*text;
+	NCURSES_SIZE_T	firstchar;
+	NCURSES_SIZE_T	lastchar;
+	NCURSES_SIZE_T	oldindex;
+};
+#endif
+
 /*  */
 
 static struct swit switches[] = {
