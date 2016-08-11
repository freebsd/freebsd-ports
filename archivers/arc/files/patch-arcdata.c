--- arcdata.c.orig	2010-08-07 13:06:42 UTC
+++ arcdata.c
@@ -35,7 +35,7 @@ char            tmpchr[2] = "-";/* Tempo
 #if	GEMDOS
 int		hold = 0;	/* true to pause before exit */
 #endif
-int             warn = 1;	/* true to print warnings */
+int             arcwarn = 1;	/* true to print warnings */
 int             note = 1;	/* true to print comments */
 int             bose = 0;	/* true to be verbose */
 int             nocomp = 0;	/* true to suppress compression */
