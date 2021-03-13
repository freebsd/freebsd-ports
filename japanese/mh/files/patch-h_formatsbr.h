--- h/formatsbr.h.orig	1993-12-01 04:00:26 UTC
+++ h/formatsbr.h
@@ -32,7 +32,7 @@ struct comp {
 
 extern int fmt_norm;
 
-struct	comp	*wantcomp[128];	/* hash table for deciding if a
+extern struct	comp	*wantcomp[128];	/* hash table for deciding if a
 				 * component is "interesting" */
 
 /* 
