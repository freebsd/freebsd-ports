--- matrix/matrix.cpp.orig	Mon May 13 14:07:45 2002
+++ matrix/matrix.cpp	Thu Nov 30 23:43:36 2006
@@ -54,19 +54,19 @@
   if ( this == &a )
     return *this;
   
-  if ( a.rows() != rows() || a.cols() != cols() ){
-    resize(a.rows(),a.cols()) ;
+  if ( a.rows() != this->rows() || a.cols() != this->cols() ){
+    this->resize(a.rows(),a.cols()) ;
   }
   
-  int sze = rows()*cols() ;
+  int sze = this->rows()*this->cols() ;
   T *ptr, *aptr ;
-  ptr = m-1 ;
+  ptr = this->m-1 ;
   aptr = a.m-1 ;
   
   for (i = sze; i > 0; --i)
     *(++ptr) = *(++aptr) ;
   
-  by_columns = a.by_columns;
+  this->by_columns = a.by_columns;
   
   return *this;
 }
@@ -100,10 +100,10 @@
 {
   int rwz,coz,i,j;
   
-  if ( rows() % a.rows() != 0 || cols() % a.cols() != 0 || rows() < a.rows() || cols() < a.cols() )
+  if ( this->rows() % a.rows() != 0 || this->cols() % a.cols() != 0 || this->rows() < a.rows() || this->cols() < a.cols() )
     {
 #ifdef USE_EXCEPTION
-      throw WrongSize2D(rows(),cols(),a.rows(),a.cols()) ;
+      throw WrongSize2D(this->rows(),this->cols(),a.rows(),a.cols()) ;
 #else
       Error error("Matrix<T>::submatrix");
       error << "Matrix and submatrix incommensurate" ;
@@ -111,10 +111,10 @@
 #endif
     }
   
-  if ( sr >= rows()/a.rows() || sr < 0 || sc >= cols()/a.cols() || sc < 0 )
+  if ( sr >= this->rows()/a.rows() || sr < 0 || sc >= this->cols()/a.cols() || sc < 0 )
     {
 #ifdef USE_EXCEPTION
-      throw OutOfBound2D(sr,sc,0,rows()/a.rows()-1,0,cols()/a.cols()-1) ;
+      throw OutOfBound2D(sr,sc,0,this->rows()/a.rows()-1,0,this->cols()/a.cols()-1) ;
 #else
       Error error("Matrix<T>::submatrix");
       error << "Submatrix location out of bounds.\nrowblock " << sr << ", " << rows()/a.rows() << " colblock " << sc << ", " << a.cols() << endl ;
@@ -133,7 +133,7 @@
   aptr = a.m - 1;
   for ( i = a.rows()-1; i >= 0; --i )
     {
-      ptr = &m[(i+rwz)*cols()+coz]-1 ;
+      ptr = &this->m[(i+rwz)*this->cols()+coz]-1 ;
       for ( j = a.cols(); j > 0; --j)
 	*(++ptr) = *(++aptr) ;
     }  
@@ -159,7 +159,7 @@
   // Assign matrix a to this matrix at (i,j)
   int i, j;
   
-  if ( (rw + a.rows()) > rows() || ( cl + a.cols()) > cols()) {
+  if ( (rw + a.rows()) > this->rows() || ( cl + a.cols()) > this->cols()) {
 #ifdef USE_EXCEPTION
     throw MatrixErr();
 #else
@@ -177,7 +177,7 @@
   T *pptr,*aptr ;
   aptr = a.m-1 ;
   for ( i = 0; i<a.rows(); ++i) {
-    pptr = &m[(i+rw)*cols()+cl]-1 ;
+    pptr = &this->m[(i+rw)*this->cols()+cl]-1 ;
     for ( j = 0; j < a.cols(); ++j)
       *(++pptr) = *(++aptr);
   }
@@ -208,7 +208,7 @@
 Matrix<T> Matrix<T>::get(int rw, int cl, int nr, int nc) const
 {
   Matrix<T> getmat(nr,nc) ;
-  if ( (rw+nr) > rows() || (cl+nc) > cols()) {
+  if ( (rw+nr) > this->rows() || (cl+nc) > this->cols()) {
 #ifdef USE_EXCEPTION
     throw MatrixErr();
 #else
@@ -228,7 +228,7 @@
   T *pptr,*aptr ;
   aptr = getmat.m-1;
   for (i = 0; i < nr; ++i) {
-    pptr = &m[(i+rw)*cols()+cl]-1 ;
+    pptr = &this->m[(i+rw)*this->cols()+cl]-1 ;
     for ( j = 0; j < nc; ++j)
       *(++aptr) = *(++pptr) ;
   }
@@ -252,11 +252,11 @@
   double sum, maxsum;
   int init=0 ;
   T *pptr ;
-  pptr = m-1 ;
+  pptr = this->m-1 ;
   maxsum = 0 ; // Silence the warning message
-  for(i=0;i<rows();++i){
+  for(i=0;i<this->rows();++i){
     sum = 0 ;
-    for ( j = 0; j < cols(); ++j) 
+    for ( j = 0; j < this->cols(); ++j) 
       sum += *(++pptr) ;
     if(init)
       maxsum = (maxsum>sum) ? maxsum : sum;
@@ -285,12 +285,12 @@
 {
   int i, iend;
   
-  iend = rows();
-  if ( iend > cols() )
-    iend = cols();
+  iend = this->rows();
+  if ( iend > this->cols() )
+    iend = this->cols();
   
   for (i = iend-1; i >=0; --i)
-    elem(i,i) = a;
+    this->elem(i,i) = a;
 
 }
 
@@ -308,10 +308,10 @@
 template <class T>
 Vector<T> Matrix<T>::getDiag(){
   int i, iend;
-  Vector<T> vec(minimum(rows(),cols())) ;
-  iend = minimum(rows(),cols());
+  Vector<T> vec(minimum(this->rows(),this->cols())) ;
+  iend = minimum(this->rows(),this->cols());
   for (i = iend-1; i >=0; --i)
-      vec[i] = elem(i,i);
+      vec[i] = this->elem(i,i);
   return vec ;
 }
 
@@ -328,8 +328,8 @@
 Matrix<T>& Matrix<T>::operator+=(double a)
 {
   T *p1 ;
-  p1 = m-1 ;
-  const int size = rows()*cols() ;
+  p1 = this->m-1 ;
+  const int size = this->rows()*this->cols() ;
   for(int i=size; i>0; --i)
     *(++p1) += a ;  
   return *this ;
@@ -348,8 +348,8 @@
 Matrix<T>& Matrix<T>::operator-=(double a)
 {
   T *p1 ;
-  p1 = m-1 ;
-  const int size = rows()*cols() ;
+  p1 = this->m-1 ;
+  const int size = this->rows()*this->cols() ;
   for(int i=size; i>0; --i)
     *(++p1) -= a ;  
   return *this ;
@@ -368,8 +368,8 @@
 Matrix<T>& Matrix<T>::operator*=(double a)
 {
   T *p1 ;
-  p1 = m-1 ;
-  const int size = rows()*cols() ;
+  p1 = this->m-1 ;
+  const int size = this->rows()*this->cols() ;
   for(int i=size; i>0; --i)
     *(++p1) *= a ;  
   return *this ;
@@ -388,8 +388,8 @@
 Matrix<T>& Matrix<T>::operator/=(double a)
 {
   T *p1 ;
-  p1 = m-1 ;
-  const int size = rows()*cols() ;
+  p1 = this->m-1 ;
+  const int size = this->rows()*this->cols() ;
   for(int i=size; i>0; --i)
     *(++p1) /= a ;  
   return *this ;
@@ -408,15 +408,15 @@
 template <class T> 
 Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &a)
 {
-  if ( a.rows() != rows() || a.cols() != cols() )
+  if ( a.rows() != this->rows() || a.cols() != this->cols() )
     {
 #ifdef USE_EXCEPTION
-      throw WrongSize2D(rows(),cols(),a.rows(),a.cols());
+      throw WrongSize2D(this->rows(),this->cols(),a.rows(),a.cols());
 #else
       Error error("Matrix<T>::operator+=") ;
-      if ( rows() != a.rows() )
+      if ( this->rows() != a.rows() )
 	error << "Matrices are of diferent size, a.rows() = " << rows() << " and b.rows() = " << a.rows() << endl ;
-      if ( cols() != a.cols())
+      if ( this->cols() != a.cols())
 	error << "Matrices are of diferent size, a.cols() = " << cols() << " and b.cols() = " << a.cols() << endl ;
       error.fatal() ;
 #endif
@@ -425,8 +425,8 @@
   int i, sze ;
   T *aptr,*sptr ;
   aptr = a.m - 1 ;
-  sptr = m - 1 ;
-  sze = rows()*cols() ;
+  sptr = this->m - 1 ;
+  sze = this->rows()*this->cols() ;
   for (i = sze; i > 0; --i){
       *(++sptr) += *(++aptr) ;
   }
@@ -468,16 +468,16 @@
 template <class T> 
 Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &a)
 {
-  if ( a.rows() != rows() || a.cols() != cols() )
+  if ( a.rows() != this->rows() || a.cols() != this->cols() )
     {
 #ifdef USE_EXCEPTION
-      throw WrongSize2D(rows(),cols(),a.rows(),a.cols());
+      throw WrongSize2D(this->rows(),this->cols(),a.rows(),a.cols());
 #else
       Error error("Matrix<T>::operator-=") ;
-      if ( rows() != a.rows() )
-	error << "Matrices are of diferent size, a.rows() = " << rows() << " and b.rows() = " << a.rows() << endl ;
-      if ( cols() != a.cols())
-	error << "Matrices are of diferent size, a.cols() = " << cols() << " and b.cols() = " << a.cols() << endl ;
+      if ( this->rows() != a.rows() )
+	error << "Matrices are of diferent size, a.rows() = " << this->rows() << " and b.rows() = " << a.rows() << endl ;
+      if ( this->cols() != a.cols())
+	error << "Matrices are of diferent size, a.cols() = " << this->cols() << " and b.cols() = " << a.cols() << endl ;
       error.fatal() ;
 #endif
     }
@@ -485,8 +485,8 @@
   int i, size;
   T *aptr,*sptr ;
   aptr = a.m - 1 ;
-  sptr = m - 1 ;
-  size = rows()*cols() ;
+  sptr = this->m - 1 ;
+  size = this->rows()*this->cols() ;
   for (i = size; i > 0; --i){
       *(++sptr) -= *(++aptr) ;
   }
@@ -742,14 +742,14 @@
 template <class T>
 T Matrix<T>::trace() const
 {
-  int size = rows();
+  int size = this->rows();
   T sum = (T)0;
   
-  if ( size > cols() )
-    size = cols();
+  if ( size > this->cols() )
+    size = this->cols();
   
   for (int d = 0; d < size; ++d)
-    sum += elem(d,d) ;
+    sum += this->elem(d,d) ;
   
   return sum;
 }
@@ -770,12 +770,12 @@
 template <class T>
 Matrix<T> Matrix<T>::herm() const
 {
-  int i, j, r = cols(), c = rows();
+  int i, j, r = this->cols(), c = this->rows();
   Matrix<T> adj(r,c);
   
   for (i = 0; i < r; ++i)
     for (j = 0; j < c; ++j)
-      adj.elem(i,j) = elem(j,i) ;
+      adj.elem(i,j) = this->elem(j,i) ;
 
   return adj;
 
@@ -794,11 +794,11 @@
 template <class T>
 Matrix<T> Matrix<T>::flop() const
 {					
-  Matrix<T> f(rows(),cols()) ;
-  for(int i=rows()-1;i>=0;--i)
-    for(int j=cols()-1;j>=0;--j)
+  Matrix<T> f(this->rows(),this->cols()) ;
+  for(int i=this->rows()-1;i>=0;--i)
+    for(int j=this->cols()-1;j>=0;--j)
       {
-	f(i,j) = elem(i,cols()-j-1);
+	f(i,j) = this->elem(i,this->cols()-j-1);
       }
   return f; 
 }
@@ -817,13 +817,13 @@
 {					
   // same as hermitian for real Matrix<T>
   int i, j;
-  const int& r = cols();
-  const int& c = rows();
+  const int& r = this->cols();
+  const int& c = this->rows();
   Matrix<T> adj(r,c);
   
   for (i = r-1; i >=0; --i)
     for (j = c-1; j >=0; --j)
-      adj.elem(i,j) = elem(j,i) ;
+      adj.elem(i,j) = this->elem(j,i) ;
   
   
   return adj; 
@@ -844,7 +844,7 @@
 int Matrix<T>::read(char* filename) {
   ifstream fin(filename) ;
   if(!fin) {
-    resize(1,1) ;
+    this->resize(1,1) ;
     return 0 ;
   }
   int r,c ;
@@ -855,8 +855,8 @@
   if(r) return 0 ;
   if(!fin.read((char*)&r,sizeof(int))) return 0 ;
   if(!fin.read((char*)&c,sizeof(int))) return 0 ;
-  resize(r,c) ;
-  if(!fin.read((char*)m,sizeof(T)*r*c)) return 0 ;
+  this->resize(r,c) ;
+  if(!fin.read((char*)this->m,sizeof(T)*r*c)) return 0 ;
 
   delete []type ;
   return 1 ;
@@ -877,11 +877,11 @@
 int Matrix<T>::read(char* filename,int r, int c) {
   ifstream fin(filename) ;
   if(!fin) {
-    resize(1,1) ;
+    this->resize(1,1) ;
     return 0 ;
   }
-  resize(r,c) ;
-  if(!fin.read((char*)m,sizeof(T)*r*c)) return 0 ;
+  this->resize(r,c) ;
+  if(!fin.read((char*)this->m,sizeof(T)*r*c)) return 0 ;
 
   return 1 ;
 }
@@ -904,11 +904,11 @@
   if(!fout)
     return 0 ;
   int r,c ;
-  r = rows() ; c = cols() ;
+  r = this->rows() ; c = this->cols() ;
   if(!fout.write((char*)&"matrix",sizeof(char)*6)) return 0 ;
   if(!fout.write((char*)&r,sizeof(int))) return 0 ;
   if(!fout.write((char*)&c,sizeof(int))) return 0 ;
-  if(!fout.write((char*)m,sizeof(T)*r*c)) return 0 ;
+  if(!fout.write((char*)this->m,sizeof(T)*r*c)) return 0 ;
   return 1;
 }
 
@@ -927,7 +927,7 @@
   ofstream fout(filename) ;
   if(!fout)
     return 0 ;
-  if(!fout.write((char*)m,sizeof(T)*rows()*cols())) return 0 ;
+  if(!fout.write((char*)this->m,sizeof(T)*this->rows()*this->cols())) return 0 ;
   return 1;
 }
 
