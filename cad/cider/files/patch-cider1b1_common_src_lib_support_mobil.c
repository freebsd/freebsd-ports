--- cider1b1/common/src/lib/support/mobil.c.orig	1994-01-29 19:29:43.000000000 +0000
+++ cider1b1/common/src/lib/support/mobil.c
@@ -304,7 +304,7 @@ double *pMup;
       *pMup = info->muMax[HOLE][MAJOR];
     }
   }
-  return;
+  return (0);
 }
 
 MOBfieldDep (info, carrier, field, pMu, pDMu)
@@ -321,7 +321,7 @@ double *pDMu;
 
   /* Quick check to make sure we really belong here. */
   if (!FieldDepMobility)
-    return;
+    return (0);
 
   sgnL = SGN (field);
   eLateral = ABS (field);
@@ -413,5 +413,5 @@ double *pDMu;
   *pMu = mu;
   *pDMu = dMuDEl;
 
-  return;
+  return (0);
 }
