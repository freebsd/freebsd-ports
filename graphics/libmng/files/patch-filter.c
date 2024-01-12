--- libmng_filter.c	2012-07-29 15:26:34.000000000 -0400
+++ libmng_filter.c	2024-01-08 14:25:01.379756000 -0500
@@ -207,7 +207,7 @@
     iC  = (mng_uint32)*pPriorx_prev;
     iP  = iA + iB - iC;
-    iPa = abs (iP - iA);
-    iPb = abs (iP - iB);
-    iPc = abs (iP - iC);
+    iPa = iP > iA ? iP - iA : iA - iP;
+    iPb = iP > iB ? iP - iB : iB - iP;
+    iPc = iP > iC ? iP - iC : iC - iP;
 
     if ((iPa <= iPb) && (iPa <= iPc))
