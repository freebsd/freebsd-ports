--- src/genetic_algorithm_lib.c.orig	2000-10-28 13:04:39 UTC
+++ src/genetic_algorithm_lib.c
@@ -3,9 +3,8 @@
 #endif
 #include <string.h>
 
-#include <values.h>
-#include <math.h>
 #include <sys/types.h>
+#include <math.h>
 #include <errno.h>
 #include "yagi.h"
 
@@ -245,7 +244,7 @@ int Selection(FILE *fd, int gen)
 	GeneRecord *temp ;
 	double minfit,maxfit ;
 	sigma=0.0 ;
-	minfit=MAXDOUBLE ; 
+	minfit=MAXFLOAT;
 	maxfit=-minfit ;
 	/* minfit=1e308; maxfit=-1e308; XXXXXXXXXXXXXXXXXXXXXX */
 	for(a=0 ; a<population_size ; a++ ) 
