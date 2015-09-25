--- bwtgap.h.orig	2014-02-25 21:20:01 UTC
+++ bwtgap.h
@@ -5,9 +5,9 @@
 #include "bwtaln.h"
 
 typedef struct { // recursion stack
-	u_int32_t info; // score<<21 | i
-	u_int32_t n_mm:8, n_gapo:8, n_gape:8, state:2, n_seed_mm:6;
-	u_int32_t n_ins:16, n_del:16;
+	uint32_t info; // score<<21 | i
+	uint32_t n_mm:8, n_gapo:8, n_gape:8, state:2, n_seed_mm:6;
+	uint32_t n_ins:16, n_del:16;
 	int last_diff_pos;
 	bwtint_t k, l; // (k,l) is the SA region of [i,n-1]
 } gap_entry_t;
