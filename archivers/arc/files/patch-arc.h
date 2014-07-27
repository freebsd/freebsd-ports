--- ./arc.h.orig	Tue Aug 10 23:03:24 1999
+++ ./arc.h	Tue Aug 10 23:01:55 1999
@@ -106,7 +106,7 @@
 #if	GEMDOS
 extern int      hold;		/* hold screen before exiting */
 #endif
-extern int      warn;		/* true to print warnings */
+extern int      arcwarn;	/* true to print warnings */
 extern int      note;		/* true to print comments */
 extern int      bose;		/* true to be verbose */
 extern int      nocomp;		/* true to suppress compression */
