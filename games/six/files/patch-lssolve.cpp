--- six/lssolve.cpp.orig	Fri Feb 20 15:34:59 2004
+++ six/lssolve.cpp	Fri Feb 20 15:36:58 2004
@@ -120,7 +120,7 @@
   double temp;
 
   x(n - 1) = b(n - 1) / U(n - 1, n - 1);
-  if(isnan(x(n - 1)))
+  if(std::isnan(x(n - 1)))
      x(n - 1) = 0.;
   for(i = n - 2; i >= 0; i--) {
     // Should be: x(i)=((b(i)-U(i,i,i+1,n-1)*x(i+1,n-1))/U(i,i))(0);
@@ -131,7 +131,7 @@
       temp += U.data()[iPos + j] * x(j);
     }
     x(i) = (b(i) - temp) / U.data()[iPos + i];
-    if(isnan(x(i)))
+    if(std::isnan(x(i)))
        x(i) = 0.;
   }
 }
