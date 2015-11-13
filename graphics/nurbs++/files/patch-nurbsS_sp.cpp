--- nurbs/nurbsS_sp.cpp.orig	Mon May 13 14:07:46 2002
+++ nurbs/nurbsS_sp.cpp	Fri Dec  1 00:52:04 2006
@@ -43,7 +43,7 @@
 */
 template <class T, int N>
 void NurbsSurfaceSP<T,N>::updateMaxU() {
-  if(degU>3){
+  if(this->degU>3){
 #ifdef USE_EXCEPTION
     throw NurbsInputError();
 #else
@@ -53,12 +53,12 @@
 #endif
   }
   else{
-    maxU.resize(P.rows()) ;
-    maxAtU_.resize(P.rows()) ;
-    for(int i=0;i<P.rows();++i){
-      if(!maxInfluence(i,U,degU,maxAtU_[i]))
+    maxU.resize(this->P.rows()) ;
+    maxAtU_.resize(this->P.rows()) ;
+    for(int i=0;i<this->P.rows();++i){
+      if(!maxInfluence(i,this->U,this->degU,maxAtU_[i]))
 	cerr << "Problem in maxInfluence U!\n" ;
-      maxU[i] = nurbsBasisFun(maxAtU_[i],i,degU,U) ;
+      maxU[i] = nurbsBasisFun(maxAtU_[i],i,this->degU,this->U) ;
     }
     
   }
@@ -78,7 +78,7 @@
 */
 template <class T, int N>
 void NurbsSurfaceSP<T,N>::updateMaxV() {
-  if(degV>3){
+  if(this->degV>3){
 #ifdef USE_EXCEPTION
     throw NurbsInputError();
 #else
@@ -88,12 +88,12 @@
 #endif
   }
   else{
-    maxV.resize(P.cols()) ;
-    maxAtV_.resize(P.cols()) ;
-    for(int i=0;i<P.cols();++i){
-      if(!maxInfluence(i,V,degV,maxAtV_[i]))
+    maxV.resize(this->P.cols()) ;
+    maxAtV_.resize(this->P.cols()) ;
+    for(int i=0;i<this->P.cols();++i){
+      if(!maxInfluence(i,this->V,this->degV,maxAtV_[i]))
 	cerr << "Problem in maxInfluence V!\n" ;
-      maxV[i] = nurbsBasisFun(maxAtV_[i],i,degV,V) ;
+      maxV[i] = nurbsBasisFun(maxAtV_[i],i,this->degV,this->V) ;
     }
     
   }
@@ -124,11 +124,11 @@
 NurbsSurfaceSP<T,N> NurbsSurfaceSP<T,N>::generateParallel(T d) const {
   NurbsSurfaceSP<T,N> p(*this) ;
 
-  Vector< Point_nD<T,N> > offset(P.rows()*P.cols()) ;
-  Vector<T> ur(P.rows()*P.cols()) ;
-  Vector<T> vr(P.rows()*P.cols()) ;
-  Vector_INT Du(P.rows()*P.cols()) ;
-  Vector_INT Dv(P.rows()*P.cols()) ;
+  Vector< Point_nD<T,N> > offset(this->P.rows()*this->P.cols()) ;
+  Vector<T> ur(this->P.rows()*this->P.cols()) ;
+  Vector<T> vr(this->P.rows()*this->P.cols()) ;
+  Vector_INT Du(this->P.rows()*this->P.cols()) ;
+  Vector_INT Dv(this->P.rows()*this->P.cols()) ;
 
   Du.reset(0) ;
   Dv.reset(0) ;
@@ -137,10 +137,10 @@
 
   no = 0 ;
 
-  for(i=0;i<P.rows();++i)
-    for(j=0;j<P.cols();++j){
+  for(i=0;i<this->P.rows();++i)
+    for(j=0;j<this->P.cols();++j){
       Point_nD<T,N> norm ;
-      norm = normal(maxAtU_[i],maxAtV_[j]) ;
+      norm = this->normal(maxAtU_[i],maxAtV_[j]) ;
       if(norm.x() == T(0) && 
 	 norm.y() == T(0) &&
 	 norm.z() == T(0)){
@@ -150,26 +150,26 @@
 	// must handle the corner cases
 	int ok = 0 ; 
 	if(i==0 && j==0){
-	  norm = normal(maxAtU_[i]+delta,maxAtV_[j]) ;
-	  norm += normal(maxAtU_[i],maxAtV_[j]+delta) ;
+	  norm = this->normal(maxAtU_[i]+delta,maxAtV_[j]) ;
+	  norm += this->normal(maxAtU_[i],maxAtV_[j]+delta) ;
 	  norm /= T(2) ;
 	  ok = 1 ;
 	}
-	if(i==P.rows()-1 && j==P.cols()-1){
-	  norm = normal(maxAtU_[i]-delta,maxAtV_[j]) ;
-	  norm += normal(maxAtU_[i],maxAtV_[j]-delta) ;
+	if(i==this->P.rows()-1 && j==this->P.cols()-1){
+	  norm = this->normal(maxAtU_[i]-delta,maxAtV_[j]) ;
+	  norm += this->normal(maxAtU_[i],maxAtV_[j]-delta) ;
 	  norm /= T(2) ;
 	  ok = 1 ;
 	}
-	if(i==0 && j==P.cols()-1){
-	  norm = normal(maxAtU_[i]-delta,maxAtV_[j]) ;
-	  norm += normal(maxAtU_[i],maxAtV_[j]+delta) ;
+	if(i==0 && j==this->P.cols()-1){
+	  norm = this->normal(maxAtU_[i]-delta,maxAtV_[j]) ;
+	  norm += this->normal(maxAtU_[i],maxAtV_[j]+delta) ;
 	  norm /= T(2) ;
 	  ok = 1 ;
 	}
-	if(i==P.rows()-1 && j==0){
-	  norm = normal(maxAtU_[i]-delta,maxAtV_[j]) ;
-	  norm += normal(maxAtU_[i],maxAtV_[j]+delta) ;
+	if(i==this->P.rows()-1 && j==0){
+	  norm = this->normal(maxAtU_[i]-delta,maxAtV_[j]) ;
+	  norm += this->normal(maxAtU_[i],maxAtV_[j]+delta) ;
 	  norm /= T(2) ;
 	  ok = 1 ;
 	}
@@ -178,7 +178,7 @@
 	  while(norm.x() == T(0) && 
 	     norm.y() == T(0) &&
 	     norm.z() == T(0)){
-	    if( nt*d >(U[U.n()-1]-U[0])){
+	    if( nt*d >(this->U[this->U.n()-1]-this->U[0])){
 #ifdef USE_EXCEPTION
 	      throw NurbsComputationError();
 #else
@@ -188,22 +188,22 @@
 #endif
 	    }
 	    T u1,u2,v1,v2 ;
-	    if(i==0 || i==P.rows()-1){
+	    if(i==0 || i==this->P.rows()-1){
 	      u1 = u2 = maxAtU_[i] ;
 	      v1 = maxAtV_[j]+ nt*delta ;
 	      v2 = maxAtV_[j]- nt*delta ;
-	      if(v1>V[V.n()-1]) v1 = V[V.n()-1] ;
-	      if(v2<V[0]) v2 = V[0] ;
-	      norm = normal(u1,v1);
-	      norm += normal(u2,v2) ;
+	      if(v1>this->V[this->V.n()-1]) v1 = this->V[this->V.n()-1] ;
+	      if(v2<this->V[0]) v2 = this->V[0] ;
+	      norm = this->normal(u1,v1);
+	      norm += this->normal(u2,v2) ;
 	      norm /= 2 ; 
 	    }
 	    else{
 	      u1 = maxAtU_[i]- nt*delta ;
 	      u2 = maxAtU_[i]+ nt*delta ;
 	      v1 = v2 = maxAtV_[j] ;
-	      if(u1 < U[0]) u1 = U[0] ;
-	      if(u2 > U[U.n()-1]) u2 = U[U.n()-1] ;
+	      if(u1 < this->U[0]) u1 = this->U[0] ;
+	      if(u2 > this->U[this->U.n()-1]) u2 = this->U[this->U.n()-1] ;
 
 	      T u3,v3 ;
 	      u3 = maxAtU_[i] ;
@@ -212,12 +212,12 @@
 	      else
 		v3 = maxAtV_[j]- nt*delta ;
 
-	      if(v3<V[0]) v3 = V[0] ;
-	      if(v3>V[V.n()-1]) v3 = V[V.n()-1] ;
+	      if(v3<this->V[0]) v3 = this->V[0] ;
+	      if(v3>this->V[this->V.n()-1]) v3 = this->V[this->V.n()-1] ;
 
-	      norm = normal(u1,v1);
-	      norm += normal(u2,v2) ;
-	      norm += normal(u3,v3) ;
+	      norm = this->normal(u1,v1);
+	      norm += this->normal(u2,v2) ;
+	      norm += this->normal(u3,v3) ;
 	      norm /= 3 ; 
 	    }
 	    nt *= 10.0 ; 
@@ -263,13 +263,13 @@
 
   int sizeU, sizeV ;
 
-  sizeU = 2*degU+3 ; 
-  if(i-degU-1<0) sizeU += i-degU-1 ; 
-  if(i+degU+1>=P.rows()) sizeU -= i+degU+1-P.rows() ;
-
-  sizeV = 2*degV+3 ;
-  if(j-degV-1<0) sizeV += j-degV-1 ; 
-  if(j+degV+1>=P.cols()) sizeV -= j+degV+1-P.cols() ;
+  sizeU = 2*this->degU+3 ; 
+  if(i-this->degU-1<0) sizeU += i-this->degU-1 ; 
+  if(i+this->degU+1>=this->P.rows()) sizeU -= i+this->degU+1-this->P.rows() ;
+
+  sizeV = 2*this->degV+3 ;
+  if(j-this->degV-1<0) sizeV += j-this->degV-1 ; 
+  if(j+this->degV+1>=this->P.cols()) sizeV -= j+this->degV+1-this->P.cols() ;
   
   Vector<T> u(sizeU) ;
   Vector<T> v(sizeV) ;
@@ -280,16 +280,16 @@
   int n=0;
   int nu = 0 ;
   int nv = 0 ; 
-  for(int k=i-degU-1;k<=i+degU+1;++k){
+  for(int k=i-this->degU-1;k<=i+this->degU+1;++k){
     if(k<0)
       continue ;
-    if(k>=P.rows())
+    if(k>=this->P.rows())
       break ; 
     nv = 0 ;
-    for(int l=j-degV-1;l<=j+degV+1;++l){
+    for(int l=j-this->degV-1;l<=j+this->degV+1;++l){
       if(l<0)
 	continue ;
-      if(l>=P.cols())
+      if(l>=this->P.cols())
 	break ; 
       if( k == i && j==l){
 	pts[n].x() = a.x() ; 
@@ -316,7 +316,7 @@
   pu.resize(n) ; 
   pv.resize(n) ; 
 
-  movePoint(u,v,pts,pu,pv) ;
+  this->movePoint(u,v,pts,pu,pv) ;
 }
 
 } // end namespace
