--- arc.h.orig	2013-06-27 02:00:19 UTC
+++ arc.h
@@ -104,7 +104,7 @@ extern int      hold;		/* hold screen before exiting *
 #if	GEMDOS
 extern int      hold;		/* hold screen before exiting */
 #endif
-extern int      warn;		/* true to print warnings */
+extern int      arcwarn;	/* true to print warnings */
 extern int      note;		/* true to print comments */
 extern int      bose;		/* true to be verbose */
 extern int      nocomp;		/* true to suppress compression */
