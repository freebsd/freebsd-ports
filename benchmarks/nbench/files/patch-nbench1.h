--- nbench1.h.orig	2004-12-30 02:15:18 UTC
+++ nbench1.h
@@ -355,7 +355,7 @@ int learned;            /* flag--if TRUE
 ** The Neural Net test requires an input data file.
 ** The name is specified here.
 */
-char *inpath="NNET.DAT";
+char *inpath=DATADIR "NNET.DAT";
 
 /*
 ** PROTOTYPES
