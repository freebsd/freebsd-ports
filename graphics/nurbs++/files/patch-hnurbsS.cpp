--- nurbs/hnurbsS.cpp.orig	Fri May 17 11:24:21 2002
+++ nurbs/hnurbsS.cpp	Fri Dec  1 00:40:08 2006
@@ -103,11 +103,11 @@
   initBase() ;
   offset.resize(baseSurf.ctrlPnts()) ;
 
-  P = baseSurf.ctrlPnts() ;
-  U = baseSurf.knotU() ;
-  V = baseSurf.knotV() ;
-  degU = baseSurf.degreeU() ;
-  degV = baseSurf.degreeV() ;
+  this->P = baseSurf.ctrlPnts() ;
+  this->U = baseSurf.knotU() ;
+  this->V = baseSurf.knotV() ;
+  this->degU = baseSurf.degreeU() ;
+  this->degV = baseSurf.degreeV() ;
 
   //updateSurface() ;
 
@@ -162,11 +162,11 @@
   baseUpdateN = baseLevel_->modifiedN()-1 ; // Set it so that initBase will run
   initBase() ;
   offset.resize(baseSurf.ctrlPnts()) ;
-  P = baseSurf.ctrlPnts() ;
-  U = baseSurf.knotU() ;
-  V = baseSurf.knotV() ;
-  degU = baseSurf.degreeU() ;
-  degV = baseSurf.degreeV() ;
+  this->P = baseSurf.ctrlPnts() ;
+  this->U = baseSurf.knotU() ;
+  this->V = baseSurf.knotV() ;
+  this->degU = baseSurf.degreeU() ;
+  this->degV = baseSurf.degreeV() ;
   //updateSurface() ;
 
 }
@@ -200,7 +200,7 @@
   rU.resize(0) ;
   rV.resize(0) ;
 
-  offset = P ;
+  offset = this->P ;
 }
 
 /*!
@@ -334,11 +334,11 @@
   }
   if(baseLevel_){
     if(initBase()){
-      P = baseSurf.ctrlPnts() ;
-      U = baseSurf.knotU() ;
-      V = baseSurf.knotV() ;
-      degU = baseSurf.degreeU() ;
-      degV = baseSurf.degreeV() ;
+      this->P = baseSurf.ctrlPnts() ;
+      this->U = baseSurf.knotU() ;
+      this->V = baseSurf.knotV() ;
+      this->degU = baseSurf.degreeU() ;
+      this->degV = baseSurf.degreeV() ;
     }
     if(i0>=0 && j0>=0){
       Point_nD<T,N> vecOffset ;
@@ -352,13 +352,13 @@
 	  offset(i0,j0).y()*jvec(i0,j0) +
 	  offset(i0,j0).z()*kvec(i0,j0) ;
       }
-      P(i0,j0).x() = baseSurf.ctrlPnts()(i0,j0).x()+vecOffset.x() ;
-      P(i0,j0).y() = baseSurf.ctrlPnts()(i0,j0).y()+vecOffset.y() ;
-      P(i0,j0).z() = baseSurf.ctrlPnts()(i0,j0).z()+vecOffset.z() ;
+      this->P(i0,j0).x() = baseSurf.ctrlPnts()(i0,j0).x()+vecOffset.x() ;
+      this->P(i0,j0).y() = baseSurf.ctrlPnts()(i0,j0).y()+vecOffset.y() ;
+      this->P(i0,j0).z() = baseSurf.ctrlPnts()(i0,j0).z()+vecOffset.z() ;
     }
     else{
-      for(int i=0;i<P.rows();++i)
-	for(int j=0;j<P.cols();++j){
+      for(int i=0;i<this->P.rows();++i)
+	for(int j=0;j<this->P.cols();++j){
 	  if(offset(i,j).x() != 0 || 
 	     offset(i,j).y() != 0 || offset(i,j).z() || 0){
 	    Point_nD<T,N> vecOffset ;
@@ -372,20 +372,20 @@
 		offset(i,j).y()*jvec(i,j) +
 		offset(i,j).z()*kvec(i,j) ;
 	    }
-	    P(i,j).x() = baseSurf.ctrlPnts()(i,j).x()+vecOffset.x() ;
-	    P(i,j).y() = baseSurf.ctrlPnts()(i,j).y()+vecOffset.y() ;
-	    P(i,j).z() = baseSurf.ctrlPnts()(i,j).z()+vecOffset.z() ;
+	    this->P(i,j).x() = baseSurf.ctrlPnts()(i,j).x()+vecOffset.x() ;
+	    this->P(i,j).y() = baseSurf.ctrlPnts()(i,j).y()+vecOffset.y() ;
+	    this->P(i,j).z() = baseSurf.ctrlPnts()(i,j).z()+vecOffset.z() ;
 	  }
 	}
     }
   }
   else{
     if(i0>=0 && j0>=0)
-      P(i0,j0) = offset(i0,j0) ;
+      this->P(i0,j0) = offset(i0,j0) ;
     else{
-      for(int i=0;i<P.rows();++i)
-	for(int j=0;j<P.cols();++j){
-	  P(i,j) = offset(i,j) ;
+      for(int i=0;i<this->P.rows();++i)
+	for(int j=0;j<this->P.cols();++j){
+	  this->P(i,j) = offset(i,j) ;
 	}
     }
   }
@@ -554,17 +554,17 @@
       return mod ;
   }
 
-  if(u<knotU()[0] || u>knotU()[knotU().n()-1])
+  if(u<this->knotU()[0] || u>this->knotU()[this->knotU().n()-1])
     return -1 ;
-  if(v<knotV()[0] || v>knotU()[knotV().n()-1])
+  if(v<this->knotV()[0] || v>this->knotU()[this->knotV().n()-1])
     return -1 ;
 
-  int su = findSpanU(u) ;
-  int sv = findSpanV(v) ;
+  int su = this->findSpanU(u) ;
+  int sv = this->findSpanV(v) ;
 
-  for(int i=0;i<=degU;++i)
-    for(int j=0;j<=degV;++j){
-      if(offset(su-degU+i,sv+degV+j) != HPoint_nD<T,N>(0,0,0,0))
+  for(int i=0;i<=this->degU;++i)
+    for(int j=0;j<=this->degV;++j){
+      if(offset(su-this->degU+i,sv+this->degV+j) != HPoint_nD<T,N>(0,0,0,0))
 	return level_ ;
     }
 
@@ -742,16 +742,16 @@
 template <class T, int N>
 void HNurbsSurface<T,N>::splitUV(int nu, int nv, Vector<T> &nU, Vector<T> &nV){
 
-  nU.resize(knotU().n()*nu) ;
-  nV.resize(knotV().n()*nv) ;
+  nU.resize(this->knotU().n()*nu) ;
+  nV.resize(this->knotV().n()*nv) ;
   
   int i,j,n ;
 
   n = 0 ; 
-  for(i=1;i<knotU().n();++i){
-    if(knotU()[i] >knotU()[i-1]){
-      T a = knotU()[i-1] ;
-      T b = knotU()[i] ;
+  for(i=1;i<this->knotU().n();++i){
+    if(this->knotU()[i] >this->knotU()[i-1]){
+      T a = this->knotU()[i-1] ;
+      T b = this->knotU()[i] ;
 
 
       for(j=0;j<nu;++j){
@@ -763,10 +763,10 @@
   nU.resize(n) ;
 
   n = 0 ;
-  for(i=1;i<knotV().n();++i){
-    if(knotV()[i] > knotV()[i-1]){
-      T a = knotV()[i-1] ;
-      T b = knotV()[i] ;
+  for(i=1;i<this->knotV().n();++i){
+    if(this->knotV()[i] > this->knotV()[i-1]){
+      T a = this->knotV()[i-1] ;
+      T b = this->knotV()[i] ;
 
       for(j=0;j<nv;++j){
 	nV[n] = a + (b-a)*T(j+1)/T(nv+1) ;
@@ -805,22 +805,22 @@
   int i,j,n ;
 
   if(su<=0)
-    su = degU  ;
+    su = this->degU  ;
   if(sv<=0)
-    sv = degV  ;
-  if(su>degU+1)
-    su = degU+1 ;
-  if(sv>degV+1)
-    sv = degV+1 ;
+    sv = this->degV  ;
+  if(su>this->degU+1)
+    su = this->degU+1 ;
+  if(sv>this->degV+1)
+    sv = this->degV+1 ;
 
-  nU.resize(knotU().n()*nu*su) ;
-  nV.resize(knotV().n()*nv*sv) ;
+  nU.resize(this->knotU().n()*nu*su) ;
+  nV.resize(this->knotV().n()*nv*sv) ;
   
   n = 0 ; 
-  for(i=1;i<knotU().n();++i){
-    if(knotU()[i] >knotU()[i-1]){
-      T a = knotU()[i-1] ;
-      T b = knotU()[i] ;
+  for(i=1;i<this->knotU().n();++i){
+    if(this->knotU()[i] >this->knotU()[i-1]){
+      T a = this->knotU()[i-1] ;
+      T b = this->knotU()[i] ;
 
 
       for(j=0;j<nu;++j){
@@ -835,10 +835,10 @@
   nU.resize(n) ;
 
   n = 0 ;
-  for(i=1;i<knotV().n();++i){
-    if(knotV()[i] > knotV()[i-1]){
-      T a = knotV()[i-1] ;
-      T b = knotV()[i] ;
+  for(i=1;i<this->knotV().n();++i){
+    if(this->knotV()[i] > this->knotV()[i-1]){
+      T a = this->knotV()[i-1] ;
+      T b = this->knotV()[i] ;
 
       for(j=0;j<nv;++j){
 	T v = a + (b-a)*T(j+1)/T(nv+1) ;
@@ -1014,10 +1014,10 @@
     if(!fin.read((char*)&du,sizeof(int))) { delete []type ; return 0 ;}
     if(!fin.read((char*)&dv,sizeof(int))) { delete []type ; return 0 ;}
     
-    resize(nu,nv,du,dv) ;
+    this->resize(nu,nv,du,dv) ;
     
-    if(!fin.read((char*)U.memory(),sizeof(T)*U.n())) { delete []type ; return 0 ;}
-    if(!fin.read((char*)V.memory(),sizeof(T)*V.n())) { delete []type ; return 0 ;}
+    if(!fin.read((char*)this->U.memory(),sizeof(T)*this->U.n())) { delete []type ; return 0 ;}
+    if(!fin.read((char*)this->V.memory(),sizeof(T)*this->V.n())) { delete []type ; return 0 ;}
     
     if(!r1){
       p = new T[3*nu*nv] ;
@@ -1025,10 +1025,10 @@
       p2 = p ;
       for(int i=0;i<nu;i++)
 	for(int j=0;j<nv;j++){
-	  P(i,j).x() = *(p++) ;
-	  P(i,j).y() = *(p++) ;
-	  P(i,j).z() = *(p++) ;
-	  P(i,j).w() = 1.0 ;
+	  this->P(i,j).x() = *(p++) ;
+	  this->P(i,j).y() = *(p++) ;
+	  this->P(i,j).z() = *(p++) ;
+	  this->P(i,j).w() = 1.0 ;
 	}
       delete []p2 ;
     }
@@ -1038,14 +1038,14 @@
       p2 = p ;
       for(int i=0;i<nu;i++)
 	for(int j=0;j<nv;j++){
-	  P(i,j).x() = *(p++) ;
-	  P(i,j).y() = *(p++) ;
-	  P(i,j).z() = *(p++) ;
-	  P(i,j).w() = *(p++) ;
+	  this->P(i,j).x() = *(p++) ;
+	  this->P(i,j).y() = *(p++) ;
+	  this->P(i,j).z() = *(p++) ;
+	  this->P(i,j).w() = *(p++) ;
 	}
       delete []p2 ;
     }
-    offset = P ;
+    offset = this->P ;
     this->updateSurface() ;
   }
   else { // reading the offset information
@@ -1144,29 +1144,29 @@
   if(!fout)
     return 0 ;
   if(!baseLevel_){
-    int prows = P.rows();
-    int pcols = P.cols();
+    int prows = this->P.rows();
+    int pcols = this->P.cols();
     char st = '0' + sizeof(T) ; 
     if(!fout.write((char*)&"hns4",sizeof(char)*4)) return 0 ;
     if(!fout.write((char*)&st,sizeof(char))) return 0 ; 
     if(!fout.write((char*)&prows,sizeof(int))) return 0 ;
     if(!fout.write((char*)&pcols,sizeof(int))) return 0 ;
-    if(!fout.write((char*)&degU,sizeof(int))) return 0 ;
-    if(!fout.write((char*)&degV,sizeof(int))) return 0 ;
-    if(!fout.write((char*)U.memory(),sizeof(T)*U.n())) return 0 ;
-    if(!fout.write((char*)V.memory(),sizeof(T)*V.n())) return 0 ;
+    if(!fout.write((char*)&this->degU,sizeof(int))) return 0 ;
+    if(!fout.write((char*)&this->degV,sizeof(int))) return 0 ;
+    if(!fout.write((char*)this->U.memory(),sizeof(T)*this->U.n())) return 0 ;
+    if(!fout.write((char*)this->V.memory(),sizeof(T)*this->V.n())) return 0 ;
     
     T *p,*p2 ;
-    p = new T[P.rows()*P.cols()*4] ;
+    p = new T[this->P.rows()*this->P.cols()*4] ;
     p2 = p ;
-    for(int i=0;i<P.rows();i++) 
-      for(int j=0;j<P.cols();j++){
+    for(int i=0;i<this->P.rows();i++) 
+      for(int j=0;j<this->P.cols();j++){
 	*p = offset(i,j).x() ; p++ ;
 	*p = offset(i,j).y() ; p++ ;
 	*p = offset(i,j).z() ; p++ ;
 	*p = offset(i,j).w() ; p++ ;
       }
-    if(!fout.write((char*)p2,sizeof(T)*P.rows()*P.cols()*4)) return 0 ;
+    if(!fout.write((char*)p2,sizeof(T)*this->P.rows()*this->P.cols()*4)) return 0 ;
     delete []p2 ;
   }
   else{
@@ -1282,7 +1282,7 @@
   int i,j ;
   j = 0 ;
   for(i=0;i<X.n();++i){
-    if(X[i]>=U[0] && X[i]<=U[U.n()-1]){
+    if(X[i]>=this->U[0] && X[i]<=this->U[this->U.n()-1]){
       Xu[j] = X[i] ;
       ++j ;
     }
@@ -1294,7 +1294,7 @@
       nextLevel_->refineKnotU(Xu) ;
     }
     
-    NurbsSurface<T,N> osurf(degU,degV,U,V,offset) ;
+    NurbsSurface<T,N> osurf(this->degU,this->degV,this->U,this->V,offset) ;
     
     osurf.refineKnotU(Xu) ;
     
@@ -1324,7 +1324,7 @@
   int i,j ;
   j = 0 ;
   for(i=0;i<X.n();++i){
-    if(X[i]>=V[0] && X[i]<=V[V.n()-1]){
+    if(X[i]>=this->V[0] && X[i]<=this->V[this->V.n()-1]){
       Xv[j] = X[i] ;
       ++j ;
     }
@@ -1336,7 +1336,7 @@
       nextLevel_->refineKnotV(Xv) ;
     }
     
-    NurbsSurface<T,N> osurf(degU,degV,U,V,offset) ;
+    NurbsSurface<T,N> osurf(this->degU,this->degV,this->U,this->V,offset) ;
     
     osurf.refineKnotV(Xv) ;
     
@@ -1370,26 +1370,26 @@
 */
 template <class T, int N>
 int HNurbsSurface<T,N>::movePointOffset(T u, T v, const Point_nD<T,N>& delta){
-  P = offset ; 
+  this->P = offset ; 
 
   // by definition the offset has w = 0 , but this isn't valid for
   // the control points, increasing the w by 1, will generate a valid surface
   if(baseLevel_)
-    for(int i=0;i<P.rows();++i)
-      for(int j=0;j<P.cols();++j){
-	P(i,j).w() += T(1) ; 
+    for(int i=0;i<this->P.rows();++i)
+      for(int j=0;j<this->P.cols();++j){
+	this->P(i,j).w() += T(1) ; 
       }
 
   if(NurbsSurface<T,N>::movePoint(u,v,delta)){
-    offset = P ;
+    offset = this->P ;
     // need to reset the offset weights
     if(baseLevel_)
-      for(int i=0;i<P.rows();++i)
-	for(int j=0;j<P.cols();++j){
-	  P(i,j).w() -= T(1) ; 
+      for(int i=0;i<this->P.rows();++i)
+	for(int j=0;j<this->P.cols();++j){
+	  this->P(i,j).w() -= T(1) ; 
       }
     
-    P = baseSurf.ctrlPnts() ; 
+    this->P = baseSurf.ctrlPnts() ; 
     updateSurface() ; 
     return 1 ;
   }
