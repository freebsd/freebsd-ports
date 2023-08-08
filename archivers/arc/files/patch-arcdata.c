--- arcdata.c.orig	2013-06-27 02:00:19 UTC
+++ arcdata.c
@@ -33,7 +33,7 @@ int		hold = 0;	/* true to pause before exit */
 #if	GEMDOS
 int		hold = 0;	/* true to pause before exit */
 #endif
-int             warn = 1;	/* true to print warnings */
+int             arcwarn = 1;	/* true to print warnings */
 int             note = 1;	/* true to print comments */
 int             bose = 0;	/* true to be verbose */
 int             nocomp = 0;	/* true to suppress compression */
