--- src/Sqrt.cpp.orig	Fri Aug 13 04:51:58 2004
+++ src/Sqrt.cpp	Sun Sep 12 00:32:59 2004
@@ -37,15 +37,15 @@
 
   if (uv.type==MN_REAL && lv.type==MN_REAL) {
 
-     if (lv.R<0) {
-            if ((((int)uv.R)&1)==1) { //negative, odd
-            value.SetReal(-pow(-lv.R,(1.0/uv.R)));
+     if (lv.mpl.m.R<0) {
+            if ((((int)uv.mpl.m.R)&1)==1) { //negative, odd
+            value.SetReal(-pow(-lv.mpl.m.R,(1.0/uv.mpl.m.R)));
             return(value);
             }
-            else lv.type=MN_COMPLEX, lv.I=0; //negative, even
+            else lv.type=MN_COMPLEX, lv.mpl.m.I=0; //negative, even
      }
      else {
-         value.SetReal(pow(lv.R,(1.0/uv.R)));
+         value.SetReal(pow(lv.mpl.m.R,(1.0/uv.mpl.m.R)));
          return(value);
      }
   }
