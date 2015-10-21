--- nurbs/nurbs_sp.cpp.orig	Mon May 13 14:07:46 2002
+++ nurbs/nurbs_sp.cpp	Fri Dec  1 00:46:20 2006
@@ -41,7 +41,7 @@
 */
 template <class T, int N>
 void NurbsCurveSP<T,N>::updateMaxU() {
-  if(deg_>3){
+  if(this->deg_>3){
 #ifdef USE_EXCEPTION
     throw NurbsInputError();
 #else
@@ -51,10 +51,10 @@
 #endif
   }
   else{
-    maxU.resize(P.n()) ;
-    maxAt_.resize(P.n()) ;
-    for(int i=0;i<P.n();++i){
-      if(!maxInfluence(i,U,deg_,maxAt_[i]))
+    maxU.resize(this->P.n()) ;
+    maxAt_.resize(this->P.n()) ;
+    for(int i=0;i<this->P.n();++i){
+      if(!maxInfluence(i,this->U,this->deg_,maxAt_[i]))
 	cerr << "Problem in maxInfluence U!\n" ;
       if(i>0)
 	if(maxAt_[i]<maxAt_[i-1]){
@@ -63,13 +63,13 @@
 #else
 	  Error error("Error updating maxU");
 	  error << "HUGE ERROR!\n" ;
-	  error << "Knot = " << U << endl ;
+	  error << "Knot = " << this->U << endl ;
 	  error << " i = " << i << endl ;
-	  error << " deg = " << deg_ << endl ;
+	  error << " deg = " << this->deg_ << endl ;
 	  error.fatal() ; 
 #endif
 	}
-      maxU[i] = basisFun(maxAt_[i],i,deg_) ;
+      maxU[i] = this->basisFun(maxAt_[i],i,this->deg_) ;
     }
     
   }
@@ -96,14 +96,14 @@
 */
 template <class T, int N>
 void NurbsCurveSP<T,N>::modOnlySurfCPby(int i, const HPoint_nD<T,N>& a){
-  Vector<T> u(2*deg_+3) ;
-  Vector< Point_nD<T,N> > pts(2*deg_+3) ; 
+  Vector<T> u(2*this->deg_+3) ;
+  Vector< Point_nD<T,N> > pts(2*this->deg_+3) ; 
 
   int n=0;
-  for(int j=i-deg_-1;j<=i+deg_+1;++j){
+  for(int j=i-this->deg_-1;j<=i+this->deg_+1;++j){
     if(j<0)
       continue ;
-    if(j>=P.n())
+    if(j>=this->P.n())
       break ; 
     u[n] = maxAt_[j] ;
     if( j == i){
@@ -119,7 +119,7 @@
   u.resize(n) ;
   pts.resize(n) ; 
 
-  movePoint(u,pts) ;
+  this->movePoint(u,pts) ;
 }
 
 } // end namespace
