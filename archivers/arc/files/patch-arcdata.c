--- ./arcdata.c.orig	Tue Aug 10 23:03:24 1999
+++ ./arcdata.c	Tue Aug 10 23:01:56 1999
@@ -35,7 +35,7 @@
 #if	GEMDOS
 int		hold = 0;	/* true to pause before exit */
 #endif
-int             warn = 1;	/* true to print warnings */
+int             arcwarn = 1;	/* true to print warnings */
 int             note = 1;	/* true to print comments */
 int             bose = 0;	/* true to be verbose */
 int             nocomp = 0;	/* true to suppress compression */
