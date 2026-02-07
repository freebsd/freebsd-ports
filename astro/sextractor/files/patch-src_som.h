--- src/som.h.orig	2005-10-24 11:48:52 UTC
+++ src/som.h
@@ -58,7 +58,7 @@ typedef struct
   float		stderror;		/* Global reduced error */
   }	somstruct;
 
-somstruct	*thesom;
+EXTERN somstruct	*thesom;
 
 /*---------------------------------- protos --------------------------------*/
 
