--- src/Math_functions.cpp.orig	Sun Dec  8 05:04:06 2002
+++ src/Math_functions.cpp	Sun Sep 12 01:04:56 2004
@@ -15,9 +15,9 @@
 
 math_node mpl_neg(math_node a)
 {
-        if (a.type==MN_REAL)     a.R=-a.R;
-				if (a.type==MN_COMPLEX)  a.R=-a.R, a.I=-a.I;
-				if (a.type==MN_VECTOR)   a.I=-a.I, a.J=-a.J, a.K=-a.K;
+        if (a.type==MN_REAL)     a.mpl.m.R=-a.mpl.m.R;
+				if (a.type==MN_COMPLEX)  a.mpl.m.R=-a.mpl.m.R, a.mpl.m.I=-a.mpl.m.I;
+				if (a.type==MN_VECTOR)   a.mpl.m.I=-a.mpl.m.I, a.mpl.m.J=-a.mpl.m.J, a.mpl.m.K=-a.mpl.m.K;
         return(a);
 }
 
@@ -28,17 +28,17 @@
         ans.type=MN_NULL;
 
         if (a.type==MN_REAL) {
-               if (b.type==MN_REAL) ans.R=a.R+b.R, ans.type=MN_REAL;
-               else if (b.type==MN_COMPLEX) ans.R=a.R+b.R, ans.I=b.I, ans.type=MN_COMPLEX;            
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R+b.mpl.m.R, ans.type=MN_REAL;
+               else if (b.type==MN_COMPLEX) ans.mpl.m.R=a.mpl.m.R+b.mpl.m.R, ans.mpl.m.I=b.mpl.m.I, ans.type=MN_COMPLEX;            
         }
         else
         if (a.type==MN_COMPLEX) {
-               if (b.type==MN_REAL) ans.R=a.R+b.R, ans.I=a.I, ans.type=MN_COMPLEX;
-               else if (b.type==MN_COMPLEX) ans.R=a.R+b.R, ans.I=a.I+b.I, ans.type=MN_COMPLEX;           
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R+b.mpl.m.R, ans.mpl.m.I=a.mpl.m.I, ans.type=MN_COMPLEX;
+               else if (b.type==MN_COMPLEX) ans.mpl.m.R=a.mpl.m.R+b.mpl.m.R, ans.mpl.m.I=a.mpl.m.I+b.mpl.m.I, ans.type=MN_COMPLEX;           
         }
         else 
         if (a.type==MN_VECTOR) {
-               if (b.type==MN_VECTOR) ans.I=a.I+b.I, ans.J=a.J+b.J, ans.K=a.K+b.K, ans.type=MN_VECTOR;
+               if (b.type==MN_VECTOR) ans.mpl.m.I=a.mpl.m.I+b.mpl.m.I, ans.mpl.m.J=a.mpl.m.J+b.mpl.m.J, ans.mpl.m.K=a.mpl.m.K+b.mpl.m.K, ans.type=MN_VECTOR;
         }
 
         return(ans);
@@ -51,17 +51,17 @@
         ans.type=MN_NULL;
 
         if (a.type==MN_REAL) {
-               if (b.type==MN_REAL) ans.R=a.R-b.R, ans.type=MN_REAL;
-               else if (b.type==MN_COMPLEX) ans.R=a.R-b.R, ans.I=0-b.I, ans.type=MN_COMPLEX;          
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R-b.mpl.m.R, ans.type=MN_REAL;
+               else if (b.type==MN_COMPLEX) ans.mpl.m.R=a.mpl.m.R-b.mpl.m.R, ans.mpl.m.I=0-b.mpl.m.I, ans.type=MN_COMPLEX;          
         }
         else
         if (a.type==MN_COMPLEX) {
-               if (b.type==MN_REAL) ans.R=a.R-b.R, ans.I=a.I, ans.type=MN_COMPLEX;
-               else if (b.type==MN_COMPLEX) ans.R=a.R-b.R, ans.I=a.I-b.I, ans.type=MN_COMPLEX;
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R-b.mpl.m.R, ans.mpl.m.I=a.mpl.m.I, ans.type=MN_COMPLEX;
+               else if (b.type==MN_COMPLEX) ans.mpl.m.R=a.mpl.m.R-b.mpl.m.R, ans.mpl.m.I=a.mpl.m.I-b.mpl.m.I, ans.type=MN_COMPLEX;
         }
         else 
         if (a.type==MN_VECTOR) {
-               if (b.type==MN_VECTOR) ans.I=a.I-b.I, ans.J=a.J-b.J, ans.K=a.K-b.K, ans.type=MN_VECTOR;
+               if (b.type==MN_VECTOR) ans.mpl.m.I=a.mpl.m.I-b.mpl.m.I, ans.mpl.m.J=a.mpl.m.J-b.mpl.m.J, ans.mpl.m.K=a.mpl.m.K-b.mpl.m.K, ans.type=MN_VECTOR;
         }
 
         return(ans);
@@ -73,19 +73,19 @@
         ans.type=MN_NULL;
 
         if (a.type==MN_REAL) {
-               if (b.type==MN_REAL) ans.R=a.R*b.R, ans.type=MN_REAL;
-               else if (b.type==MN_COMPLEX) ans.R=a.R*b.R, ans.I=a.R*b.I, ans.type=MN_COMPLEX;
-               else if (b.type==MN_VECTOR) ans.I=a.R*b.I, ans.J=a.R*b.J, ans.K=a.R*b.K, ans.type=MN_VECTOR;
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R*b.mpl.m.R, ans.type=MN_REAL;
+               else if (b.type==MN_COMPLEX) ans.mpl.m.R=a.mpl.m.R*b.mpl.m.R, ans.mpl.m.I=a.mpl.m.R*b.mpl.m.I, ans.type=MN_COMPLEX;
+               else if (b.type==MN_VECTOR) ans.mpl.m.I=a.mpl.m.R*b.mpl.m.I, ans.mpl.m.J=a.mpl.m.R*b.mpl.m.J, ans.mpl.m.K=a.mpl.m.R*b.mpl.m.K, ans.type=MN_VECTOR;
         }
         else
         if (a.type==MN_COMPLEX) {
-               if (b.type==MN_REAL) ans.R=a.R*b.R, ans.I=a.I*b.R, ans.type=MN_COMPLEX;
-               else if (b.type==MN_COMPLEX) ans.R=a.R*b.R-a.I*b.I, ans.I=a.R*b.I+a.I*b.R, ans.type=MN_COMPLEX;
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R*b.mpl.m.R, ans.mpl.m.I=a.mpl.m.I*b.mpl.m.R, ans.type=MN_COMPLEX;
+               else if (b.type==MN_COMPLEX) ans.mpl.m.R=a.mpl.m.R*b.mpl.m.R-a.mpl.m.I*b.mpl.m.I, ans.mpl.m.I=a.mpl.m.R*b.mpl.m.I+a.mpl.m.I*b.mpl.m.R, ans.type=MN_COMPLEX;
         }
         else 
         if (a.type==MN_VECTOR) {  // Dot product
-               if (b.type==MN_VECTOR) ans.R=a.I*b.I+a.J*b.J+a.K*b.K, ans.type=MN_REAL;
-               else if (b.type==MN_REAL) ans.I=a.I*b.R, ans.J=a.J*b.R, ans.K=a.K*b.R, ans.type=MN_VECTOR;
+               if (b.type==MN_VECTOR) ans.mpl.m.R=a.mpl.m.I*b.mpl.m.I+a.mpl.m.J*b.mpl.m.J+a.mpl.m.K*b.mpl.m.K, ans.type=MN_REAL;
+               else if (b.type==MN_REAL) ans.mpl.m.I=a.mpl.m.I*b.mpl.m.R, ans.mpl.m.J=a.mpl.m.J*b.mpl.m.R, ans.mpl.m.K=a.mpl.m.K*b.mpl.m.R, ans.type=MN_VECTOR;
         }
 
         return(ans);
@@ -99,19 +99,19 @@
         ans.type=MN_NULL;
 
         if (a.type==MN_REAL) {
-               if (b.type==MN_REAL) ans.R=a.R/b.R, ans.type=MN_REAL; // ok
-               else if (b.type==MN_COMPLEX) { opz=mpl_opz(b.Complex()); ans.R=a.R*opz.R, ans.I=a.R*opz.I, ans.type=MN_COMPLEX; }
-               else if (b.type==MN_VECTOR) ans.I=a.R/b.I, ans.J=a.R/b.J, ans.K=a.R/b.K, ans.type=MN_VECTOR;
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R/b.mpl.m.R, ans.type=MN_REAL; // ok
+               else if (b.type==MN_COMPLEX) { opz=mpl_opz(b.Complex()); ans.mpl.m.R=a.mpl.m.R*opz.mpl.m.R, ans.mpl.m.I=a.mpl.m.R*opz.mpl.m.I, ans.type=MN_COMPLEX; }
+               else if (b.type==MN_VECTOR) ans.mpl.m.I=a.mpl.m.R/b.mpl.m.I, ans.mpl.m.J=a.mpl.m.R/b.mpl.m.J, ans.mpl.m.K=a.mpl.m.R/b.mpl.m.K, ans.type=MN_VECTOR;
         }
         else
         if (a.type==MN_COMPLEX) {
-               if (b.type==MN_REAL) ans.R=a.R*(1/b.R), ans.I=a.I*(1/b.R), ans.type=MN_COMPLEX;
-               else if (b.type==MN_COMPLEX) { opz=mpl_opz(b.Complex()); ans.R=a.R*opz.R-a.I*opz.I, ans.I=a.R*opz.I+a.I*opz.R, ans.type=MN_COMPLEX; }
+               if (b.type==MN_REAL) ans.mpl.m.R=a.mpl.m.R*(1/b.mpl.m.R), ans.mpl.m.I=a.mpl.m.I*(1/b.mpl.m.R), ans.type=MN_COMPLEX;
+               else if (b.type==MN_COMPLEX) { opz=mpl_opz(b.Complex()); ans.mpl.m.R=a.mpl.m.R*opz.mpl.m.R-a.mpl.m.I*opz.mpl.m.I, ans.mpl.m.I=a.mpl.m.R*opz.mpl.m.I+a.mpl.m.I*opz.mpl.m.R, ans.type=MN_COMPLEX; }
         }
         else
         if (a.type==MN_VECTOR) {
-               if (b.type==MN_VECTOR) ans.I=a.I/b.I, ans.J=a.J/b.J, ans.K=a.K/b.K, ans.type=MN_VECTOR;
-               else if (b.type==MN_REAL) ans.I=a.I/b.R, ans.J=a.J/b.R, ans.K=a.K/b.R, ans.type=MN_VECTOR;
+               if (b.type==MN_VECTOR) ans.mpl.m.I=a.mpl.m.I/b.mpl.m.I, ans.mpl.m.J=a.mpl.m.J/b.mpl.m.J, ans.mpl.m.K=a.mpl.m.K/b.mpl.m.K, ans.type=MN_VECTOR;
+               else if (b.type==MN_REAL) ans.mpl.m.I=a.mpl.m.I/b.mpl.m.R, ans.mpl.m.J=a.mpl.m.J/b.mpl.m.R, ans.mpl.m.K=a.mpl.m.K/b.mpl.m.R, ans.type=MN_VECTOR;
         }
 
         return(ans);
@@ -135,28 +135,28 @@
 
 math_node::math_node(mpl_real r)
 {
-real=r;
+mpl.real=r;
 type=MN_REAL;
 }
 
 
 math_node::math_node(mpl_complex z)
 {
-complex=z;
+mpl.complex=z;
 type=MN_COMPLEX;
 }
 
 
 math_node::math_node(mpl_rational r)
 {
-rational=r;
+mpl.rational=r;
 type=MN_RATIONAL;
 }
 
 
 math_node::math_node(mpl_vector v)
 {
-vector=v;
+mpl.vector=v;
 type=MN_VECTOR;
 }
 
@@ -166,7 +166,7 @@
 
 void math_node::Clear()
 {
-R=I=K=J=0.0;
+mpl.m.R=mpl.m.I=mpl.m.K=mpl.m.J=0.0;
 type=MN_REAL;
 }
 
@@ -180,48 +180,48 @@
 
 void math_node::SetReal(mpl_real x)
 {
-real=x;
+mpl.real=x;
 type=MN_REAL;
 }
 
 
 void math_node::SetComplex(mpl_complex z)
 {
-complex=z;
+mpl.complex=z;
 type=MN_COMPLEX;
 }
 
 
 void math_node::SetRational(mpl_rational r)
 {
-rational=r;
+mpl.rational=r;
 type=MN_RATIONAL;
 }
 
 
 mpl_real math_node::Real()
 {
-    if (type==MN_RATIONAL) return(R/I);
-    return(real);
+    if (type==MN_RATIONAL) return(mpl.m.R/mpl.m.I);
+    return(mpl.real);
 }
 
 
 mpl_complex math_node::Complex()
 {  
-    if (type==MN_REAL) complex.i=0; 
-    return(complex);
+    if (type==MN_REAL) mpl.complex.i=0; 
+    return(mpl.complex);
 }
 
 
 mpl_rational math_node::Rational()
 {
-    return(rational);
+    return(mpl.rational);
 }
 
 
 mpl_vector math_node::Vector()
 {
-    return(vector);
+    return(mpl.vector);
 }
 
 
