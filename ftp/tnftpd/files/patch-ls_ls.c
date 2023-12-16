Looking at FreeBSD's manual page, it appears that FreeBSD 5.2 changed
the signature of the comparison function:

        FTS * fts_open(char * const *path_argv, int options,
                int (*compar)(const FTSENT * const *, const FTSENT * const *));

--- ls/ls.c.orig	2009-03-01 22:58:20 UTC
+++ ls/ls.c
@@ -73,7 +73,14 @@ static void	 display(FTSENT *, FTSENT *);
 #include "extern.h"
 
 static void	 display(FTSENT *, FTSENT *);
+
+/* workaround FreeBSD <fts.h> changing fts_open()'s compar signature */
+#if defined(__FreeBSD__) && defined(USE_FTS_H)
+static int	 mastercmp(const FTSENT * const *, const FTSENT * const *);
+#else
 static int	 mastercmp(const FTSENT **, const FTSENT **);
+#endif
+
 static void	 traverse(int, char **, int);
 
 static void (*printfcn)(DISPLAY *);
@@ -595,7 +602,11 @@ static int
  * All other levels use the sort function.  Error entries remain unsorted.
  */
 static int
+#if defined(__FreeBSD__) && defined(USE_FTS_H)
+mastercmp(const FTSENT * const *a, const FTSENT * const *b)
+#else
 mastercmp(const FTSENT **a, const FTSENT **b)
+#endif
 {
 	int a_info, b_info;
 
