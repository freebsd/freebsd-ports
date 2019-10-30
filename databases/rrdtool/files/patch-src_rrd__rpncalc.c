Fix UB when calculating median of all-NaN values

Corresponds to upstream commit 1d700bf

https://github.com/oetiker/rrdtool-1.x/commit/1d700bf3ba13a75b91047e6e979231abd755892b

--- src/rrd_rpncalc.c.orig	2019-05-27 18:48:09 UTC
+++ src/rrd_rpncalc.c
@@ -1197,15 +1197,16 @@ short rpn_calc(
                     }
                 }
 
+				/* when goodvals and badvals meet, they might have met on a
+				 * NAN, which wouldn't decrease final_elements. so, check
+				 * that now. */
+				if (isnan(*goodvals)) --final_elements;
+
                 stptr -= elements;
                 if (!final_elements) {
                     /* no non-NAN elements; push NAN */
                     rpnstack->s[++stptr] = DNAN;
                 } else {
-                    /* when goodvals and badvals meet, they might have met on a
-                     * NAN, which wouldn't decrease final_elements. so, check
-                     * that now. */
-                    if (isnan(*goodvals)) --final_elements;
                     /* and finally, take the median of the remaining non-NAN
                      * elements. */
                     qsort(element_ptr, final_elements, sizeof(double),
