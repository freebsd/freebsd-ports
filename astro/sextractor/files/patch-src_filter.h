--- src/filter.h.orig	2005-10-24 11:48:52 UTC
+++ src/filter.h
@@ -32,7 +32,7 @@ typedef struct structfilter
   struct structbpann	*bpann;
   }	filterstruct;
 
-filterstruct	*thefilter;
+EXTERN filterstruct	*thefilter;
 
 /*------------------------------- functions ---------------------------------*/
 void		convolve(picstruct *, PIXTYPE *),
