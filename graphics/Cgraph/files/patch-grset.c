--- grset.c.orig	Mon Jun  9 16:56:08 2003
+++ grset.c	Mon Jun  9 16:56:22 2003
@@ -14,10 +14,10 @@
 
 int cg_reset(void)
 {
-    lw_aorigin(-cgxorig,-cgyorig); /* Go to the bottom left corner of the page */
-    lw_linewidth(1.0);
-    lw_gray(0.0);
-    lw_dash(0,0.);
+    cg_aorigin(-cgxorig,-cgyorig); /* Go to the bottom left corner of the page */
+    cg_linewidth(1.0);
+    cg_gray(0.0);
+    cg_dash(0,0.);
     return(0);
 }
 
