$FreeBSD$

--- ./kspread/kspread_interpreter.cc.orig	Tue Aug 13 18:08:16 2002
+++ ./kspread/kspread_interpreter.cc	Tue Aug 13 18:09:55 2002
@@ -2547,10 +2547,10 @@
         }
   // This is not correct solution for problem with floating point numbers and probably
   // will fail in platforms where float and double lenghts are same.
-  if (approx_equal(floor(args[0]->doubleValue()*pow(10,digits)), args[0]->doubleValue()*pow(10,digits)))
+  if (approx_equal(floor(args[0]->doubleValue()*::pow(10,digits)), args[0]->doubleValue()*::pow(10,digits)))
       result = args[0]->doubleValue();
   else
-      result=floor(args[0]->doubleValue()*pow(10,digits)+1)/pow(10,digits);
+      result=floor(args[0]->doubleValue()*::pow(10,digits)+1)/::pow(10,digits);
   context.setValue( new KSValue( result) );
 
   return true;
@@ -3404,7 +3404,7 @@
         return false;
         }
 
-  double arg=pow(sqrt(pow(imag,2)+pow(real,2)),args[1]->intValue());
+  double arg=::pow(sqrt(pow(imag,2)+pow(real,2)),args[1]->intValue());
   double angle=atan(imag/real);
 
   double real_res=arg*cos(angle*args[1]->intValue());
