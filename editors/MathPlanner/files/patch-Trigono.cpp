--- src/Trigono.cpp.orig	Thu Dec 12 11:58:58 2002
+++ src/Trigono.cpp	Sun Sep 12 00:34:27 2004
@@ -37,28 +37,28 @@
 
   if (type==MN_REAL) {
 
-  if (!deg_rad) re=mpl_rad(val.R);
-  else re=val.R;
+  if (!deg_rad) re=mpl_rad(val.mpl.m.R);
+  else re=val.mpl.m.R;
 
   switch(Opr) {
   case 0: real=mpl_sin(re); break;
   case 1: real=mpl_cos(re); break;
   case 2: real=mpl_tan(re); break;
   case 3: real=1.0/mpl_tan(re); break;
-  case 4: real=asin(val.R); if (!deg_rad) real=mpl_deg(real); break;
-  case 5: real=acos(val.R); if (!deg_rad) real=mpl_deg(real); break;
-  case 6: real=atan(val.R); if (!deg_rad) real=mpl_deg(real); break;
-  case 9: real=floor(val.R); break;
-  case 10: real=val.R-floor(val.R); break;
-  case 12: real=atan(1.0/val.R); if (deg_rad==0) real=mpl_deg(real); break;
-  case 13: real=sinh(val.R); break;
-  case 14: real=cosh(val.R); break;
-  case 15: real=tanh(val.R); break;
-  case 16: real=mpl_coth(val.R); break;
-  case 17: real=mpl_asinh(val.R); break;
-  case 18: real=mpl_acosh(val.R); break;
-  case 19: real=mpl_atanh(val.R); break;
-  case 20: real=mpl_acoth(val.R); break;
+  case 4: real=asin(val.mpl.m.R); if (!deg_rad) real=mpl_deg(real); break;
+  case 5: real=acos(val.mpl.m.R); if (!deg_rad) real=mpl_deg(real); break;
+  case 6: real=atan(val.mpl.m.R); if (!deg_rad) real=mpl_deg(real); break;
+  case 9: real=floor(val.mpl.m.R); break;
+  case 10: real=val.mpl.m.R-floor(val.mpl.m.R); break;
+  case 12: real=atan(1.0/val.mpl.m.R); if (deg_rad==0) real=mpl_deg(real); break;
+  case 13: real=sinh(val.mpl.m.R); break;
+  case 14: real=cosh(val.mpl.m.R); break;
+  case 15: real=tanh(val.mpl.m.R); break;
+  case 16: real=mpl_coth(val.mpl.m.R); break;
+  case 17: real=mpl_asinh(val.mpl.m.R); break;
+  case 18: real=mpl_acosh(val.mpl.m.R); break;
+  case 19: real=mpl_atanh(val.mpl.m.R); break;
+  case 20: real=mpl_acoth(val.mpl.m.R); break;
   default: Error_flag=true; AppControl->AddError(QObject::tr("Real numbers are not supported by this function"));
   break;
   }
