--- regcomp.c.orig	2021-01-08 21:20:36 UTC
+++ regcomp.c
@@ -1415,9 +1415,9 @@ S_edit_distance(const UV* src,
 )
 {
     item *head = NULL;
-    UV swapCount, swapScore, targetCharCount, i, j;
+    UVINT swapCount, swapScore, targetCharCount, i, j;
     UV *scores;
-    UV score_ceil = x + y;
+    UVINT score_ceil = x + y;
 
     PERL_ARGS_ASSERT_EDIT_DISTANCE;
 
@@ -2188,7 +2188,7 @@ S_is_ssc_worth_it(const RExC_state_t * pRExC_state, co
             break;
         }
         end = MIN(end, max_code_points - 1);
-        count += end - start + 1;
+        count += end - (UVINT)start + 1;
         if (count >= max_match) {
             invlist_iterfinish(ssc->invlist);
             return FALSE;
@@ -9516,10 +9516,10 @@ Perl__invlist_search(SV* const invlist, const UV cp)
      *	array[i] <= cp < array[i+1]
      */
 
-    IV low = 0;
-    IV mid;
-    IV high = _invlist_len(invlist);
-    const IV highest_element = high - 1;
+    IVINT low = 0;
+    IVINT mid;
+    IVINT high = _invlist_len(invlist);
+    const IVINT highest_element = high - 1;
     const UV* array;
 
     PERL_ARGS_ASSERT__INVLIST_SEARCH;
@@ -9620,16 +9620,16 @@ Perl__invlist_union_maybe_complement_2nd(pTHX_ SV* con
 
     const UV* array_a;    /* a's array */
     const UV* array_b;
-    UV len_a;	    /* length of a's array */
-    UV len_b;
+    UVINT len_a;	    /* length of a's array */
+    UVINT len_b;
 
     SV* u;			/* the resulting union */
     UV* array_u;
-    UV len_u = 0;
+    UVINT len_u = 0;
 
-    UV i_a = 0;		    /* current index into a's array */
-    UV i_b = 0;
-    UV i_u = 0;
+    UVINT i_a = 0;		    /* current index into a's array */
+    UVINT i_b = 0;
+    UVINT i_u = 0;
 
     /* running count, as explained in the algorithm source book; items are
      * stopped accumulating and are output when the count changes to/from 0.
@@ -9841,7 +9841,7 @@ Perl__invlist_union_maybe_complement_2nd(pTHX_ SV* con
         len_u = i_u;
     }
     else {
-        IV copy_count = len_a - i_a;
+        IVINT copy_count = len_a - i_a;
         if (copy_count > 0) {   /* The non-exhausted input is 'a' */
 	    Copy(array_a + i_a, array_u + i_u, copy_count, UV);
         }
@@ -9900,16 +9900,16 @@ Perl__invlist_intersection_maybe_complement_2nd(pTHX_ 
 
     const UV* array_a;		/* a's array */
     const UV* array_b;
-    UV len_a;	/* length of a's array */
-    UV len_b;
+    UVINT len_a;	/* length of a's array */
+    UVINT len_b;
 
     SV* r;		     /* the resulting intersection */
     UV* array_r;
     UV len_r = 0;
 
-    UV i_a = 0;		    /* current index into a's array */
-    UV i_b = 0;
-    UV i_r = 0;
+    UVINT i_a = 0;		    /* current index into a's array */
+    UVINT i_b = 0;
+    UVINT i_r = 0;
 
     /* running count of how many of the two inputs are postitioned at ranges
      * that are in their sets.  As explained in the algorithm source book,
@@ -18412,7 +18412,7 @@ S_regclass(pTHX_ RExC_state_t *pRExC_state, I32 *flagp
                              * and the digit values represented are in
                              * numerical order, they are from the same series.
                              * */
-                            if (         value - prevvalue > 9
+                            if (         value - (UVINT)prevvalue > 9
                                 ||    (((    value - 0x1D7CE) % 10)
                                      <= (prevvalue - 0x1D7CE) % 10))
                             {
@@ -19032,7 +19032,7 @@ S_regclass(pTHX_ RExC_state_t *pRExC_state, I32 *flagp
 
     if (optimizable) {
         PERL_UINT_FAST8_T i;
-        UV partial_cp_count = 0;
+        UVINT partial_cp_count = 0;
         UV start[MAX_FOLD_FROMS+1] = { 0 }; /* +1 for the folded-to char */
         UV   end[MAX_FOLD_FROMS+1] = { 0 };
         bool single_range = FALSE;
@@ -19046,7 +19046,7 @@ S_regclass(pTHX_ RExC_state_t *pRExC_state, I32 *flagp
                 if (! invlist_iternext(cp_list, &start[i], &end[i])) {
                     break;
                 }
-                partial_cp_count += end[i] - start[i] + 1;
+                partial_cp_count += end[i] - (UVINT)start[i] + 1;
             }
 
             if (i == 1) {
@@ -19569,7 +19569,7 @@ S_regclass(pTHX_ RExC_state_t *pRExC_state, I32 *flagp
 
             if (invlist_highest(cp_list) <= max_permissible) {
                 UV this_start, this_end;
-                UV lowest_cp = UV_MAX;  /* init'ed to suppress compiler warn */
+                UVINT lowest_cp = UV_MAX;  /* init'ed to suppress compiler warn */
                 U8 bits_differing = 0;
                 Size_t full_cp_count = 0;
                 bool first_time = TRUE;
@@ -19604,7 +19604,7 @@ S_regclass(pTHX_ RExC_state_t *pRExC_state, I32 *flagp
                         bits_differing  |= i ^ lowest_cp;
                     }
 
-                    full_cp_count += this_end - this_start + 1;
+                    full_cp_count += this_end - (UVINT)this_start + 1;
                 }
 
                 /* At the end of the loop, we count how many bits differ from
@@ -19780,7 +19780,7 @@ S_regclass(pTHX_ RExC_state_t *pRExC_state, I32 *flagp
             && ! has_runtime_dependency
             &&   anyof_flags == 0
             &&   start[0] < (1 << ANYOFR_BASE_BITS)
-            &&   end[0] - start[0]
+            &&   end[0] - (UVINT)start[0]
                     < ((1U << (sizeof(((struct regnode_1 *)NULL)->arg1)
                                    * CHARBITS - ANYOFR_BASE_BITS))))
 
@@ -19789,7 +19789,7 @@ S_regclass(pTHX_ RExC_state_t *pRExC_state, I32 *flagp
             U8 high_utf8[UTF8_MAXBYTES+1];
 
             ret = reganode(pRExC_state, ANYOFR,
-                        (start[0] | (end[0] - start[0]) << ANYOFR_BASE_BITS));
+                        (start[0] | ((UVINT)end[0] - (UVINT)start[0]) << ANYOFR_BASE_BITS));
 
             /* Place the lowest UTF-8 start byte in the flags field, so as to
              * allow efficient ruling out at run time of many possible inputs.
