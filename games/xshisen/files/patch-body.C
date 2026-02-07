--- body.C.orig	2002-07-07 07:22:35 UTC
+++ body.C
@@ -227,7 +227,7 @@ Body::refreshhint(void)
     p = new Point[max_c][2];
     t = new Point[xsize*ysize/PKIND];
 
-    if (hintNum == 0)
+    if (hintNum != 0)
         delete[] hintArray;
     for(int i=0; i<PKIND; i++) {
         piepos[i]->GetPosArray(t, num);
