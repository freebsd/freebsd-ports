Backport of:

commit 254e4e44cd7828fba8f5bb18a7a29668221e0af5
Author: John W. O'Brien <john@saltant.com>
Date:   Sat Mar 14 08:49:47 2020 -0400

    Fix double meaning of time 0 as uninitialized value

    Treat "VRULE:0#..." as "VRULE:1#..." because elsewhere xrule==0 is
    used to mean xrule has not been set, which can lead to an array
    bounds violation.

--- src/rrd_graph_helper.c.orig	2020-03-14 17:06:47 UTC
+++ src/rrd_graph_helper.c
@@ -776,6 +776,10 @@ static graph_desc_t* newGraphDescription(image_desc_t 
               }
               if (gf==GF_VRULE){
                  gdp->xrule=val;
+                 if (gdp->xrule == 0) {
+                    /* distinguish from uninitialized */
+                    gdp->xrule++;
+                 }
               }
               else {
                  gdp->yrule=val;
