--- src/Exp_object.cpp.orig	Thu Dec 12 11:37:52 2002
+++ src/Exp_object.cpp	Sun Sep 12 00:20:21 2004
@@ -28,7 +28,7 @@
 
   if (Opr==0) {
   if (val.type==MN_REAL && eval.type==MN_REAL)
-			{ value.SetReal(pow(val.R,eval.R)); return(value); }
+			{ value.SetReal(pow(val.mpl.m.R,eval.mpl.m.R)); return(value); }
   else
   if ((val.type==MN_COMPLEX || val.type==MN_REAL) && (eval.type==MN_COMPLEX || eval.type==MN_REAL))
      { value.SetComplex(mpl_cnpower(val.Complex(),eval.Complex())); return(value); }
@@ -46,8 +46,8 @@
   eval=Inner->Calculate();
 
   if (eval.type==MN_REAL) {
-  if (Opr==1) { value.SetReal(pow(NEPER,eval.R)); return(value); }
-  if (Opr==2) { value.SetReal(pow(10,eval.R)); return(value); }
+  if (Opr==1) { value.SetReal(pow(NEPER,eval.mpl.m.R)); return(value); }
+  if (Opr==2) { value.SetReal(pow(10,eval.mpl.m.R)); return(value); }
   }
   if (eval.type==MN_COMPLEX) {
   if (Opr==1) { value.SetComplex(mpl_ce(eval.Complex())); return(value); }
