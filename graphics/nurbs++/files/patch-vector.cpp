--- matrix/vector.cpp.orig	Mon May 13 14:07:45 2002
+++ matrix/vector.cpp	Thu Nov 30 23:49:51 2006
@@ -51,16 +51,16 @@
   if(this==&b)
     return *this ;
 
-  if ( n() != b.n())
+  if ( this->n() != b.n())
     {
-      resize(b.n()) ;
+      this->resize(b.n()) ;
     }
 
-  sze = b.n() ;
+  this->sze = b.n() ;
   T *pa, *pb ;
-  pa = x-1 ;
+  pa = this->x-1 ;
   pb = b.x-1 ;
-  for(int i=n();i>0;--i){
+  for(int i=this->n();i>0;--i){
     *(++pa) = *(++pb) ;
   }
   return *this;
@@ -79,13 +79,13 @@
 template <class T>
 Vector<T>& Vector<T>::operator=(const BasicArray<T> &b)
 {
-  if ( size() != b.size())
+  if ( this->size() != b.size())
     {
-      resize(b.size()) ;
+      this->resize(b.size()) ;
     }
   T *ptr ;
-  ptr = x - 1 ;
-  for(int i=size()-1;i>=0;--i)
+  ptr = this->x - 1 ;
+  for(int i=this->size()-1;i>=0;--i)
      *(++ptr) = b[i] ;
 
   return *this;
@@ -105,9 +105,9 @@
 template <class T>
 T Vector<T>::operator=(const T d)
 {
-  const int sz = size(); 
+  const int sz = this->size(); 
   T *ptr ;
-  ptr = x-1 ;
+  ptr = this->x-1 ;
   for (int i = sz; i > 0; --i)
     *(++ptr) = d ;
 
@@ -130,19 +130,19 @@
 template <class T>
 Vector<T>& Vector<T>::operator+=(const Vector<T> &a)
 {
-  if ( a.size() != size())
+  if ( a.size() != this->size())
     {
 #ifdef USE_EXCEPTION
-      throw WrongSize(size(),a.size()) ;
+      throw WrongSize(this->size(),a.size()) ;
 #else
       Error error("Vector<T>::operator+=(Vector<T>&)");
-      error << "Vector<T> a += Vector<T> b different sizes, a = " << size() << ", b = " << a.size() ;
+      error << "Vector<T> a += Vector<T> b different sizes, a = " << this->size() << ", b = " << a.size() ;
       error.fatal() ;
 #endif
     }
-  const int sz = size();
+  const int sz = this->size();
   T *ptr,*aptr ;
-  ptr = x-1 ;
+  ptr = this->x-1 ;
   aptr = a.x-1 ;
   for (int i = sz; i >0; --i)
     *(++ptr) += *(++aptr) ;
@@ -165,20 +165,20 @@
 template <class T>
 Vector<T>& Vector<T>::operator-=(const Vector<T> &a)
 {
-  if ( a.size() != size())
+  if ( a.size() != this->size())
     {
 #ifdef USE_EXCEPTION
-      throw WrongSize(size(),a.size()) ;
+      throw WrongSize(this->size(),a.size()) ;
 #else
       Error error("Vector<T>::operator-=(Vector<T>&)");
-      error << "Vector<T> a -= Vector<T> b different sizes, a = " << size() << ", b = " << a.size() ;
+      error << "Vector<T> a -= Vector<T> b different sizes, a = " << this->size() << ", b = " << a.size() ;
       error.fatal() ;
 #endif
     }
   
-  const int sz = size(); 
+  const int sz = this->size(); 
   T *ptr,*aptr ;
-  ptr = x-1 ;
+  ptr = this->x-1 ;
   aptr = a.x-1 ;
   for (int i = sz; i > 0; --i)
     *(++ptr) -= *(++aptr) ;
@@ -391,7 +391,7 @@
     }
 
   T *aptr,*bptr ;
-  aptr = &x[i]-1 ;
+  aptr = &this->x[i]-1 ;
   bptr = b.x-1 ;
   for ( int j = b.rows(); j > 0; --j)
       *(++aptr) = *(++bptr) ;
@@ -429,7 +429,7 @@
 
   Vector<T> subvec(l) ;
   T *aptr, *bptr ;
-  aptr = &x[i] - 1 ;
+  aptr = &this->x[i] - 1 ;
   bptr = subvec.x -1 ;
   for ( int j = l; j > 0; --j)
     *(++bptr) = *(++aptr) ;
@@ -449,12 +449,12 @@
 */
 template <class T>
 int Vector<T>::minIndex() const {
-  T min = x[0] ;
+  T min = this->x[0] ;
   int index = 0 ;
 
-  for(int i=1;i<n();i++){
-    if(x[i]<=min){
-      min = x[i] ;
+  for(int i=1;i<this->n();i++){
+    if(this->x[i]<=min){
+      min = this->x[i] ;
       index = i ;
     }
   }
@@ -523,12 +523,12 @@
   T a ;
   T *v1,*v2  ;
 
-  ir = sze-1 ;
+  ir = this->sze-1 ;
   l = 0 ;
   
   while(1){
     if(ir-l<M){ // perform an insertion sort when the array is small enough
-      v1 = &x[l] ;
+      v1 = &this->x[l] ;
       for(j=l+1;j<=ir;++j){
 	a = *(++v1) ;
 	v2 = v1 ;
@@ -547,31 +547,31 @@
     }
     else{
       k=(l+ir) >> 1 ;
-      swap(x[k],x[l+1]) ;
-      if(x[l+1] > x[ir]){
-	swap(x[l+1],x[ir]) ;
+      swap(this->x[k],this->x[l+1]) ;
+      if(this->x[l+1] > this->x[ir]){
+	swap(this->x[l+1],this->x[ir]) ;
       }
-      if(x[l]> x[ir]){
-	swap(x[l],x[ir]) ;
+      if(this->x[l]> this->x[ir]){
+	swap(this->x[l],this->x[ir]) ;
       }
-      if(x[l+1] > x[l]){
-	swap(x[l+1],x[l]) ;
+      if(this->x[l+1] > this->x[l]){
+	swap(this->x[l+1],this->x[l]) ;
       }
       i=l+1 ;
       j=ir ;
-      a=x[l] ;
-      v1 = &x[i] ;
-      v2 = &x[j] ;
+      a=this->x[l] ;
+      v1 = &this->x[i] ;
+      v2 = &this->x[j] ;
       while(1){
 	while(*v1 < a) { ++i ; ++v1 ; }
 	while(*v2 > a) { --j ; --v2 ; }
 	if(j<i) break ;
 	if(*v1 == *v2)  // both are equal to a...
 	  break ;
-	swap(x[i],x[j]) ;
+	swap(this->x[i],this->x[j]) ;
       }
-      x[l] = x[j] ;
-      x[j] = a ;
+      this->x[l] = this->x[j] ;
+      this->x[j] = a ;
       jstack += 2 ;
       if(jstack>=Nstack){
 	istack.resize(istack.n()+Nstack) ; // increase the vector size
@@ -618,10 +618,10 @@
   int jstack=0;
   T a ;
 
-  ir = sze-1 ;
+  ir = this->sze-1 ;
   l = 0 ;
   
-  index.resize(sze) ;
+  index.resize(this->sze) ;
   for(i=0;i<index.n();++i)
     index[i] = i ;
 
@@ -629,9 +629,9 @@
     if(ir-l<M){ // perform an insertion sort when the array is small enough
       for(j=l+1;j<=ir;++j){
 	indext = index[j] ;
-	a = x[indext] ;
+	a = this->x[indext] ;
 	for(i=j-1;i>=0;--i){
-	  if(x[index[i]] <= a) break ;
+	  if(this->x[index[i]] <= a) break ;
 	  index[i+1] = index[i] ;
 	}
 	index[i+1] = indext ;
@@ -643,24 +643,24 @@
     else{
       k=(l+ir) >> 1 ;
       swap(index[k],index[l+1]) ;
-      if(x[index[l+1]] > x[index[ir]]){
+      if(this->x[index[l+1]] > this->x[index[ir]]){
 	swap(index[l+1],index[ir]) ;
       }
-      if(x[index[l]]> x[index[ir]]){
+      if(this->x[index[l]]> this->x[index[ir]]){
 	swap(index[l],index[ir]) ;
       }
-      if(x[index[l+1]] > x[index[l]]){
+      if(this->x[index[l+1]] > this->x[index[l]]){
 	swap(index[l+1],index[l]) ;
       }
       i=l+1 ;
       j=ir ;
       indext = index[l] ;
-      a=x[indext] ;
+      a=this->x[indext] ;
       while(1){
-	while(x[index[i]] < a) { ++i ; }
-	while(x[index[j]] > a) { --j ; }
+	while(this->x[index[i]] < a) { ++i ; }
+	while(this->x[index[j]] > a) { --j ; }
 	if(j<i) break ;
-	if(x[index[i]] == x[index[j]])
+	if(this->x[index[i]] == this->x[index[j]])
 	  break ;
 	swap(index[i],index[j]) ;
       }
