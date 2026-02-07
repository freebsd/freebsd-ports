--- nurbs/matrixRT.cpp.orig	Mon May 13 14:07:46 2002
+++ nurbs/matrixRT.cpp	Fri Dec  1 00:43:46 2006
@@ -51,13 +51,13 @@
   // *this = C.translate(x,y,z)*B.rotate(ax,ay,az) ;
   rotate(ax,ay,az) ;
 #ifdef COLUMN_ORDER
-  m[12] = x ;
-  m[13] = y ;
-  m[14] = z ;  
+  this->m[12] = x ;
+  this->m[13] = y ;
+  this->m[14] = z ;  
 #else
-  m[3] = x ;
-  m[7] = y ;
-  m[11] = z ;
+  this->m[3] = x ;
+  this->m[7] = y ;
+  this->m[11] = z ;
 #endif
 }
 
@@ -71,8 +71,8 @@
  */
 template <class T>
 MatrixRT<T>::MatrixRT() : Matrix<T>(4,4) {
-  reset(0) ;
-  diag(1.0) ;
+  this->reset(0) ;
+  this->diag(1.0) ;
 }
 
 /*!
@@ -144,33 +144,33 @@
   t10 = cos(ax);
   t13 = t4*t6;
 #ifdef COLUMN_ORDER
-  m[0] = t1*t2;
-  m[4] = -t4*t2;
-  m[8] = t6;
-  m[12] = 0 ;
-  m[1] = t7*t8+t4*t10;
-  m[5] = -t13*t8+t1*t10;
-  m[9] = -t2*t8;
-  m[13] = 0 ;
-  m[2] = -t7*t10+t4*t8;
-  m[6] = t13*t10+t1*t8;
-  m[10] = t2*t10;
-  m[14] = m[3] = m[7] = m[11] = 0.0 ;
-  m[15] = 1.0 ;
+  this->m[0] = t1*t2;
+  this->m[4] = -t4*t2;
+  this->m[8] = t6;
+  this->m[12] = 0 ;
+  this->m[1] = t7*t8+t4*t10;
+  this->m[5] = -t13*t8+t1*t10;
+  this->m[9] = -t2*t8;
+  this->m[13] = 0 ;
+  this->m[2] = -t7*t10+t4*t8;
+  this->m[6] = t13*t10+t1*t8;
+  this->m[10] = t2*t10;
+  this->m[14] = m[3] = m[7] = m[11] = 0.0 ;
+  this->m[15] = 1.0 ;
 #else
-  m[0] = t1*t2;
-  m[1] = -t4*t2;
-  m[2] = t6;
-  m[3] = 0 ;
-  m[4] = t7*t8+t4*t10;
-  m[5] = -t13*t8+t1*t10;
-  m[6] = -t2*t8;
-  m[7] = 0 ;
-  m[8] = -t7*t10+t4*t8;
-  m[9] = t13*t10+t1*t8;
-  m[10] = t2*t10;
-  m[11] = m[12] = m[13] = m[14] = 0 ;
-  m[15] = 1.0 ;
+  this->m[0] = t1*t2;
+  this->m[1] = -t4*t2;
+  this->m[2] = t6;
+  this->m[3] = 0 ;
+  this->m[4] = t7*t8+t4*t10;
+  this->m[5] = -t13*t8+t1*t10;
+  this->m[6] = -t2*t8;
+  this->m[7] = 0 ;
+  this->m[8] = -t7*t10+t4*t8;
+  this->m[9] = t13*t10+t1*t8;
+  this->m[10] = t2*t10;
+  this->m[11] = this->m[12] = this->m[13] = this->m[14] = 0 ;
+  this->m[15] = 1.0 ;
 #endif
   return *this ;
 }
@@ -203,33 +203,33 @@
   t9 = (T)sin((double)ax);
   t17 = t4*t7;
 #ifdef COLUMN_ORDER
-  m[0] = t1*t2;
-  m[4] = -t4*t5+t8*t9;
-  m[8] = t4*t9+t8*t5;
-  m[12] = 0.0 ;
-  m[1] = t4*t2;
-  m[5] = t1*t5+t17*t9;
-  m[9] = -t1*t9+t17*t5;
-  m[13] = 0.0 ;
-  m[2] = -t7;
-  m[6] = t2*t9;
-  m[10] = t2*t5;
-  m[14] = m[3] = m[7] = m[11] = 0 ;
-  m[15] = 1.0 ;
+  this->m[0] = t1*t2;
+  this->m[4] = -t4*t5+t8*t9;
+  this->m[8] = t4*t9+t8*t5;
+  this->m[12] = 0.0 ;
+  this->m[1] = t4*t2;
+  this->m[5] = t1*t5+t17*t9;
+  this->m[9] = -t1*t9+t17*t5;
+  this->m[13] = 0.0 ;
+  this->m[2] = -t7;
+  this->m[6] = t2*t9;
+  this->m[10] = t2*t5;
+  this->m[14] = m[3] = m[7] = m[11] = 0 ;
+  this->m[15] = 1.0 ;
 #else
-  m[0] = t1*t2;
-  m[1] = -t4*t5+t8*t9;
-  m[2] = t4*t9+t8*t5;
-  m[3] = 0.0 ;
-  m[4] = t4*t2;
-  m[5] = t1*t5+t17*t9;
-  m[6] = -t1*t9+t17*t5;
-  m[7] = 0.0 ;
-  m[8] = -t7;
-  m[9] = t2*t9;
-  m[10] = t2*t5;
-  m[11] = m[12] = m[13] = m[14] = 0 ;
-  m[15] = 1.0 ;
+  this->m[0] = t1*t2;
+  this->m[1] = -t4*t5+t8*t9;
+  this->m[2] = t4*t9+t8*t5;
+  this->m[3] = 0.0 ;
+  this->m[4] = t4*t2;
+  this->m[5] = t1*t5+t17*t9;
+  this->m[6] = -t1*t9+t17*t5;
+  this->m[7] = 0.0 ;
+  this->m[8] = -t7;
+  this->m[9] = t2*t9;
+  this->m[10] = t2*t5;
+  this->m[11] = this->m[12] = this->m[13] = this->m[14] = 0 ;
+  this->m[15] = 1.0 ;
 #endif
   return *this ;
 }
@@ -245,16 +245,16 @@
  */
 template <class T>
 MatrixRT<T>& MatrixRT<T>::translate(T x, T y, T z){
-  reset(0) ;
-  diag(1.0) ;
+  this->reset(0) ;
+  this->diag(1.0) ;
 #ifdef COLUMN_ORDER
-  m[12] = x ;
-  m[13] = y ;
-  m[14] = z ;
+  this->m[12] = x ;
+  this->m[13] = y ;
+  this->m[14] = z ;
 #else
-  m[3] = x ;
-  m[7] = y ;
-  m[11] = z ;
+  this->m[3] = x ;
+  this->m[7] = y ;
+  this->m[11] = z ;
 #endif
   return *this ;
 }
@@ -271,11 +271,11 @@
  */
 template <class T>
 MatrixRT<T>& MatrixRT<T>::scale(T x, T y, T z){
-  reset(0) ;
-  m[0] = x ;
-  m[5] = y ;
-  m[10] = z ;
-  m[15] = 1.0 ;
+  this->reset(0) ;
+  this->m[0] = x ;
+  this->m[5] = y ;
+  this->m[10] = z ;
+  this->m[15] = 1.0 ;
   return *this ;
 }
 
@@ -416,7 +416,7 @@
     error.fatal() ;
   }
   T *a,*b ;
-  a = m-1 ;
+  a = this->m-1 ;
   b = M[0] - 1 ;
   for(int i=0;i<16;++i){
     *(++a) = *(++b) ;
@@ -435,7 +435,7 @@
 template <class T>
 MatrixRT<T>& MatrixRT<T>::operator=(const MatrixRT<T>& M) {
   T *a,*b ;
-  a = m-1 ;
+  a = this->m-1 ;
   b = M.m - 1 ;
   for(int i=0;i<16;++i){
     *(++a) = *(++b) ;
