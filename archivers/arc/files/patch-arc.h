--- arc.h.orig	2010-08-07 13:06:42 UTC
+++ arc.h
@@ -106,7 +106,7 @@ extern char     tmpchr[2];	/* Temporary 
 #if	GEMDOS
 extern int      hold;		/* hold screen before exiting */
 #endif
-extern int      warn;		/* true to print warnings */
+extern int      arcwarn;	/* true to print warnings */
 extern int      note;		/* true to print comments */
 extern int      bose;		/* true to be verbose */
 extern int      nocomp;		/* true to suppress compression */
