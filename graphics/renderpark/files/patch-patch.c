--- patch.c~	Fri Jul 26 15:36:27 2002
+++ patch.c	Fri Jul 26 15:37:31 2002
@@ -1074,7 +1074,7 @@
   V2Sub (D, C, CD); V2Sub (D, A, AD);
   V2Add (CD, AB, AE); V2Negate (AE); V2Sub (M, A, AM);
   
-  if (fabs(DETERMINANT(AB, CD)) < EPSILON)               /* case AB /* CD */ */
+  if (fabs(DETERMINANT(AB, CD)) < EPSILON)               /* case AB CD */
     {
       V2Sub (AB, CD, Vector);
       v = DETERMINANT(AM, Vector) / DETERMINANT(AD, Vector);
@@ -1091,7 +1091,7 @@
       }
 #endif
     }
-  else if (fabs(DETERMINANT(BC, AD)) < EPSILON)          /* case AD /* BC */ */
+  else if (fabs(DETERMINANT(BC, AD)) < EPSILON)          /* case AD BC */
     {
       V2Add (AD, BC, Vector);
       u = DETERMINANT(AM, Vector) / DETERMINANT(AB, Vector);
