--- image/image.cpp.orig	Mon May 13 14:07:45 2002
+++ image/image.cpp	Thu Nov 30 23:57:14 2006
@@ -55,9 +55,9 @@
 void MatrixImage<T>::drawLine(int i1, int j1, int i2, int j2, T color){
   int i,j ;
   double mx,b ;
-  if(i1<0 || j1<0 || i1>rows() || j1>=cols()  ){
+  if(i1<0 || j1<0 || i1>this->rows() || j1>=this->cols()  ){
 #ifdef USE_EXCEPTION
-    throw OutOfBound2D(i1,j1,0,rows()-1,0,cols()-1) ;
+    throw OutOfBound2D(i1,j1,0,this->rows()-1,0,this->cols()-1) ;
 #else
     Error error("MatrixImage<T>::drawLine") ;
     error << "Error in drawing line\n Invalid index ("<< i1 << ", " << j1 << ") to ( " << i2 << ", " << j2 << ") \n" ;
@@ -65,9 +65,9 @@
 #endif
     return ;
   }
-  if(i2 <0 || j2<0 || i2>rows() || j2>=cols() ){
+  if(i2 <0 || j2<0 || i2>this->rows() || j2>=this->cols() ){
 #ifdef USE_EXCEPTION
-    throw OutOfBound2D(i2,j2,0,rows()-1,0,cols()-1) ;
+    throw OutOfBound2D(i2,j2,0,this->rows()-1,0,this->cols()-1) ;
 #else
     Error error("MatrixImage<T>::drawLine") ;
     error << "Error in drawing line\n Invalid index ("<< i1 << ", " << j1 << ") to ( " << i2 << ", " << j2 << ") \n" ;
@@ -79,7 +79,7 @@
   // check if line is vertical
   if(j1==j2){
     for(i=minimum(i1,i2);i<=maximum(i1,i2);i++)
-     operator()(i,j1) = color ;
+     this->operator()(i,j1) = color ;
     return ;
   }
   mx = (double)(i1-i2)/(double)(j1-j2) ;
@@ -88,13 +88,13 @@
     if(i1>i2){
       for(i=i1;i>=i2;i--){
 	j = int(((double)i-b)/mx) ;
-	operator()(i,j) = color ;
+	this->operator()(i,j) = color ;
       }
     }
     else{
       for(i=i1;i<=i2;i++){
 	j = (int)((i-b)/mx) ;
-	operator()(i,j) = color ;
+	this->operator()(i,j) = color ;
       }
     }
   }
@@ -102,13 +102,13 @@
     if(j1>j2){
       for(j=j1;j>=j2;j--){
 	i = (int)(mx*j+b) ;
-	operator()(i,j) = color ;
+	this->operator()(i,j) = color ;
       }
     }
     else{
       for(j=j1;j<=j2;j++){
 	i = (int)(mx*j+b) ;
-	operator()(i,j) = color ;
+	this->operator()(i,j) = color ;
       }
     }
   }
@@ -133,9 +133,9 @@
 void MatrixImage<T>::drawPoint(int i, int j, double r , T color){
   for(int y=i-int(ceil(r)) ; y<i+int(ceil(r)) ; y++)
     for(int x = j-int(ceil(r)) ; x<j+int(ceil(r)) ; x++){
-      if(y>=0 && y<rows() && x>=0 && x<cols()){
+      if(y>=0 && y<this->rows() && x>=0 && x<this->cols()){
 	if( ((y-i)*(y-i)+(x-j)*(x-j))<= r*r)
-	  operator()(y,x) = color ;
+	  this->operator()(y,x) = color ;
       }
     }
 }
@@ -153,14 +153,14 @@
 */
 template <class T>
 void MatrixImage<T>::store(Matrix<T>& a){
-  if(a.rows() != rows() || a.cols() != cols()) {
-    a.resize(rows(),cols()) ;
+  if(a.rows() != this->rows() || a.cols() != this->cols()) {
+    a.resize(this->rows(),this->cols()) ;
   }
   T *aptr, *bptr ;
   int size,i ;
   aptr = &a(0,0)-1 ;
-  bptr = m-1 ;
-  size = cols()*rows() ;
+  bptr = this->m-1 ;
+  size = this->cols()*this->rows() ;
   for(i=0;i<size;i++)
     *(++aptr) = *(++bptr) ;  
 }
