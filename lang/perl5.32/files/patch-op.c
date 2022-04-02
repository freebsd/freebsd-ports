--- op.c.orig	2021-01-08 21:20:36 UTC
+++ op.c
@@ -7030,7 +7030,7 @@ S_pmtrans(pTHX_ OP *o, OP *expr, OP *repl)
      * in real life, and could require significant memory overhead. */
     NV max_expansion = 1.;
 
-    UV t_range_count, r_range_count, min_range_count;
+    UVINT t_range_count, r_range_count, min_range_count;
     UV* t_array;
     SV* t_invlist;
     UV* r_map;
@@ -7347,7 +7347,7 @@ S_pmtrans(pTHX_ OP *o, OP *expr, OP *repl)
             bool merge_with_range_above = FALSE;
             bool merge_with_range_below = FALSE;
 
-            UV span, invmap_range_length_remaining;
+            UVINT span, invmap_range_length_remaining;
             SSize_t j;
             Size_t i;
 
@@ -7383,7 +7383,7 @@ S_pmtrans(pTHX_ OP *o, OP *expr, OP *repl)
                     {
                         t++;
                         t_range_count = valid_utf8_to_uvchr(t, &t_char_len)
-                                      - t_cp + 1;
+                                      - (UVINT)t_cp + 1;
                         t += t_char_len;
                     }
                     else {
@@ -7426,7 +7426,8 @@ S_pmtrans(pTHX_ OP *o, OP *expr, OP *repl)
                         {
                             r++;
                             r_range_count = valid_utf8_to_uvchr(r,
-                                                    &r_char_len) - r_cp + 1;
+                                                    &r_char_len) -
+                                                    (UVINT)r_cp + 1;
                             r += r_char_len;
                         }
                         else {
@@ -7483,8 +7484,8 @@ S_pmtrans(pTHX_ OP *o, OP *expr, OP *repl)
              * irrelevant if the map is to the special indicator */
 
             invmap_range_length_remaining = (i + 1 < len)
-                                            ? t_array[i+1] - t_cp
-                                            : IV_MAX - t_cp;
+                                            ? (UVINT)t_array[i+1] - (UVINT)t_cp
+                                            : IV_MAX - (UVINT)t_cp;
             span = MAX(1, MIN(min_range_count, invmap_range_length_remaining));
 
             /* The end point of this chunk is where we are, plus the span, but
@@ -7617,7 +7618,8 @@ S_pmtrans(pTHX_ OP *o, OP *expr, OP *repl)
                         && (   (   r_cp == TR_SPECIAL_HANDLING
                                 && r_map[i-1] == TR_SPECIAL_HANDLING)
                             || (   r_cp != TR_SPECIAL_HANDLING
-                                && r_cp - r_map[i-1] == t_cp - t_array[i-1])))
+                                && (UVINT)r_cp - (UVINT)r_map[i-1] ==
+                                   (UVINT)t_cp - (UVINT)t_array[i-1])))
                     {
                         merge_with_range_below = TRUE;
                     }
