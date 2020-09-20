--- src/retina.h.orig	2005-10-24 11:48:52 UTC
+++ src/retina.h
@@ -25,7 +25,7 @@ typedef struct structreti
   struct structbpann	*bpann;	/* The neural network */
   }     retistruct;
 
-retistruct	*theretina;
+EXTERN retistruct	*theretina;
 
 /*------------------------------- functions ---------------------------------*/
 
