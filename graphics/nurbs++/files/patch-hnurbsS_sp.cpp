--- nurbs/hnurbsS_sp.cpp.orig	Mon May 13 14:07:46 2002
+++ nurbs/hnurbsS_sp.cpp	Fri Dec  1 01:01:28 2006
@@ -43,7 +43,7 @@
 */
 template <class T, int N>
 void HNurbsSurfaceSP<T,N>::updateMaxU() {
-  if(degU>3){
+  if(this->degU>3){
 #ifdef USE_EXCEPTION
     throw NurbsError();
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
 void HNurbsSurfaceSP<T,N>::updateMaxV() {
-  if(degV>3){
+  if(this->degV>3){
 #ifdef USE_EXCEPTION
     throw NurbsError();
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
@@ -113,18 +113,18 @@
 */
 template <class T, int N>
 void HNurbsSurfaceSP<T,N>::modSurfCPby(int i, int j, const HPoint_nD<T,N>& a) {
-  offset(i,j) +=  a / (maxU[i]*maxV[j]) ; 
-  if(baseLevel_){
+  this->offset(i,j) +=  a / (maxU[i]*maxV[j]) ; 
+  if(this->baseLevel_){
     Point_nD<T,N> vecOffset ; 
-    vecOffset = offset(i,j).x()*ivec(i,j) +
-      offset(i,j).y()*jvec(i,j) +
-      offset(i,j).z()*kvec(i,j) ;
-    P(i,j).x() = baseSurf.ctrlPnts()(i,j).x()+vecOffset.x() ;
-    P(i,j).y() = baseSurf.ctrlPnts()(i,j).y()+vecOffset.y() ;
-    P(i,j).z() = baseSurf.ctrlPnts()(i,j).z()+vecOffset.z() ;
+    vecOffset = this->offset(i,j).x()*this->ivec(i,j) +
+      this->offset(i,j).y()*this->jvec(i,j) +
+      this->offset(i,j).z()*this->kvec(i,j) ;
+    this->P(i,j).x() = this->baseSurf.ctrlPnts()(i,j).x()+vecOffset.x() ;
+    this->P(i,j).y() = this->baseSurf.ctrlPnts()(i,j).y()+vecOffset.y() ;
+    this->P(i,j).z() = this->baseSurf.ctrlPnts()(i,j).z()+vecOffset.z() ;
   }
   else
-    P(i,j) = offset(i,j) ; 
+    this->P(i,j) = this->offset(i,j) ; 
 }
 
 /*!
@@ -151,24 +151,24 @@
 void HNurbsSurfaceSP<T,N>::modOnlySurfCPby(int i, int j, const HPoint_nD<T,N>& a){
   int k ; 
 
-  P = offset ; 
+  this->P = this->offset ; 
 
   // by definition the offset has w = 0 , but this isn't valid for
   // the control points, increasing the w by 1, will generate a valid surface
-  if(baseLevel_)
-    for(k=0;k<P.rows();++k)
-      for(int l=0;l<P.cols();++l)
-	P(k,l).w() += T(1) ; 
+  if(this->baseLevel_)
+    for(k=0;k<this->P.rows();++k)
+      for(int l=0;l<this->P.cols();++l)
+	this->P(k,l).w() += T(1) ; 
 
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
@@ -179,16 +179,16 @@
   int n=0;
   int nu = 0 ;
   int nv = 0 ; 
-  for(k=i-degU-1;k<=i+degU+1;++k){
+  for(k=i-this->degU-1;k<=i+this->degU+1;++k){
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
@@ -216,12 +216,12 @@
   pv.resize(n) ; 
 
   if(NurbsSurface<T,N>::movePoint(u,v,pts,pu,pv)){
-    offset = P ; 
+    this->offset = this->P ; 
     // an offset shouldn't have a weight value.
-    if(baseLevel_)
-      for(k=0;k<P.rows();++k)
-	for(int l=0;l<P.cols();++l)
-	  offset(k,l).w() -= T(1) ; 
+    if(this->baseLevel_)
+      for(k=0;k<this->P.rows();++k)
+	for(int l=0;l<this->P.cols();++l)
+	  this->offset(k,l).w() -= T(1) ; 
   }
   updateSurface(); 
 }
@@ -262,12 +262,12 @@
 HNurbsSurfaceSP<T,N>* HNurbsSurfaceSP<T,N>::addLevel(int n, int s) {
   HNurbsSurfaceSP<T,N> *newLevel ;
 
-  if(nextLevel_)
+  if(this->nextLevel_)
     return 0 ;
 
   Vector<T> newU,newV ;
   
-  splitUV(n,s,n,s,newU,newV) ;
+  this->splitUV(n,s,n,s,newU,newV) ;
 
   newLevel = new HNurbsSurfaceSP<T,N>(this,newU,newV) ;
 
@@ -289,7 +289,7 @@
 HNurbsSurfaceSP<T,N>* HNurbsSurfaceSP<T,N>::addLevel() {
   HNurbsSurfaceSP<T,N> *newLevel ;
 
-  if(nextLevel_)
+  if(this->nextLevel_)
     return 0 ;
 
   newLevel = new HNurbsSurfaceSP<T,N>(this) ;
@@ -311,23 +311,23 @@
   levelP = nS.nextLevel() ;
 
   NurbsSurface<T,N>::operator=(nS) ;
-  rU = nS.rU ;
-  rV = nS.rV ;
-  offset = nS.offset ;
+  this->rU = nS.rU ;
+  this->rV = nS.rV ;
+  this->offset = nS.offset ;
 
   updateMaxUV() ; 
 
-  firstLevel_ = this ;
+  this->firstLevel_ = this ;
 
   if(levelP){
     HNurbsSurfaceSP<T,N> *newLevel ;
     newLevel =  new HNurbsSurfaceSP<T,N>(this) ; 
     newLevel->copy(*levelP) ;
-    nextLevel_ = newLevel ;
-    lastLevel_ = nextLevel_->lastLevel() ;
+    this->nextLevel_ = newLevel ;
+    this->lastLevel_ = this->nextLevel_->lastLevel() ;
   }
   else{
-    lastLevel_ = this ;
+    this->lastLevel_ = this ;
   }
 
 }
@@ -349,55 +349,55 @@
 template <class T, int N>
 void HNurbsSurfaceSP<T,N>::updateSurface(int i0, int j0){
   if(i0>=0 && j0>=0){
-    if(offset(i0,j0).x()==0.0 && offset(i0,j0).y()==0.0 && offset(i0,j0).z()==0.0)
+    if(this->offset(i0,j0).x()==0.0 && this->offset(i0,j0).y()==0.0 && this->offset(i0,j0).z()==0.0)
       return ;
   }
-  if(baseLevel_){
-    if(initBase()){
-      P = baseSurf.ctrlPnts() ;
-      U = baseSurf.knotU() ;
-      V = baseSurf.knotV() ;
-      degU = baseSurf.degreeU() ;
-      degV = baseSurf.degreeV() ;
+  if(this->baseLevel_){
+    if(this->initBase()){
+      this->P = this->baseSurf.ctrlPnts() ;
+      this->U = this->baseSurf.knotU() ;
+      this->V = this->baseSurf.knotV() ;
+      this->degU = this->baseSurf.degreeU() ;
+      this->degV = this->baseSurf.degreeV() ;
       updateMaxUV() ; 
     }
     if(i0>=0 && j0>=0){
       Point_nD<T,N> vecOffset ;
-      vecOffset = offset(i0,j0).x()*ivec(i0,j0) +
-	offset(i0,j0).y()*jvec(i0,j0) +
-	offset(i0,j0).z()*kvec(i0,j0) ;
-      P(i0,j0).x() = baseSurf.ctrlPnts()(i0,j0).x()+vecOffset.x() ;
-      P(i0,j0).y() = baseSurf.ctrlPnts()(i0,j0).y()+vecOffset.y() ;
-      P(i0,j0).z() = baseSurf.ctrlPnts()(i0,j0).z()+vecOffset.z() ;
+      vecOffset = this->offset(i0,j0).x()*this->ivec(i0,j0) +
+	this->offset(i0,j0).y()*this->jvec(i0,j0) +
+	this->offset(i0,j0).z()*this->kvec(i0,j0) ;
+      this->P(i0,j0).x() = this->baseSurf.ctrlPnts()(i0,j0).x()+vecOffset.x() ;
+      this->P(i0,j0).y() = this->baseSurf.ctrlPnts()(i0,j0).y()+vecOffset.y() ;
+      this->P(i0,j0).z() = this->baseSurf.ctrlPnts()(i0,j0).z()+vecOffset.z() ;
     }
     else{
-      for(int i=0;i<P.rows();++i)
-	for(int j=0;j<P.cols();++j){
-	  if(offset(i,j).x() != 0 || 
-	     offset(i,j).y() != 0 || offset(i,j).z() || 0){
+      for(int i=0;i<this->P.rows();++i)
+	for(int j=0;j<this->P.cols();++j){
+	  if(this->offset(i,j).x() != 0 || 
+	     this->offset(i,j).y() != 0 || this->offset(i,j).z() || 0){
 	    Point_nD<T,N> vecOffset ;
-	    vecOffset = offset(i,j).x()*ivec(i,j) +
-	      offset(i,j).y()*jvec(i,j) +
-	      offset(i,j).z()*kvec(i,j) ;
-	    P(i,j).x() = baseSurf.ctrlPnts()(i,j).x()+vecOffset.x() ;
-	    P(i,j).y() = baseSurf.ctrlPnts()(i,j).y()+vecOffset.y() ;
-	    P(i,j).z() = baseSurf.ctrlPnts()(i,j).z()+vecOffset.z() ;
+	    vecOffset = this->offset(i,j).x()*this->ivec(i,j) +
+	      this->offset(i,j).y()*this->jvec(i,j) +
+	      this->offset(i,j).z()*this->kvec(i,j) ;
+	    this->P(i,j).x() = this->baseSurf.ctrlPnts()(i,j).x()+vecOffset.x() ;
+	    this->P(i,j).y() = this->baseSurf.ctrlPnts()(i,j).y()+vecOffset.y() ;
+	    this->P(i,j).z() = this->baseSurf.ctrlPnts()(i,j).z()+vecOffset.z() ;
 	  }
 	}
     }
   }
   else{
     if(i0>=0 && j0>=0)
-      P(i0,j0) = offset(i0,j0) ;
+      this->P(i0,j0) = this->offset(i0,j0) ;
     else{
-      for(int i=0;i<P.rows();++i)
-	for(int j=0;j<P.cols();++j){
-	  P(i,j) = offset(i,j) ;
+      for(int i=0;i<this->P.rows();++i)
+	for(int j=0;j<this->P.cols();++j){
+	  this->P(i,j) = this->offset(i,j) ;
 	}
     }
   }
 
-  ++updateN ;
+  ++(this->updateN) ;
 }
 
 /*!
@@ -413,7 +413,7 @@
   if(!okMax())
     updateMaxUV() ; 
   if(upLevel>=0){
-    if(level()<=upLevel){
+    if(this->level()<=upLevel){
       this->updateSurface() ;
     }
   }
@@ -421,9 +421,9 @@
     this->updateSurface() ;
   }
 
-  if(upLevel>level() || upLevel<0){
-    if(nextLevel_)
-      ((HNurbsSurfaceSP<T,N>*)nextLevel_)->updateLevels(upLevel) ;
+  if(upLevel>this->level() || upLevel<0){
+    if(this->nextLevel_)
+      ((HNurbsSurfaceSP<T,N>*)this->nextLevel_)->updateLevels(upLevel) ;
   }
 }
 
@@ -458,10 +458,10 @@
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
@@ -469,10 +469,10 @@
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
@@ -482,26 +482,26 @@
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
+    this->offset = this->P ;
     this->updateSurface() ;
   }
   else { // reading the offset information
     int ru,rv ;
     if(!fin.read((char*)&ru,sizeof(int))) { delete []type ; return 0 ;}
     if(!fin.read((char*)&rv,sizeof(int))) { delete []type ; return 0 ;}
-    rU.resize(ru) ;
-    rV.resize(rv) ;
-    if(rU.n()>0)
-      if(!fin.read((char*)rU.memory(),sizeof(T)*rU.n())) { delete []type ; return 0 ;}
-    if(rV.n()>0)
-      if(!fin.read((char*)rV.memory(),sizeof(T)*rV.n())) { delete []type ; return 0 ;}
+    this->rU.resize(ru) ;
+    this->rV.resize(rv) ;
+    if(this->rU.n()>0)
+      if(!fin.read((char*)this->rU.memory(),sizeof(T)*this->rU.n())) { delete []type ; return 0 ;}
+    if(this->rV.n()>0)
+      if(!fin.read((char*)this->rV.memory(),sizeof(T)*this->rV.n())) { delete []type ; return 0 ;}
     
     if(!fin.read((char*)&nu,sizeof(int))) { delete []type ; return 0 ;}
     if(!fin.read((char*)&nv,sizeof(int))) { delete []type ; return 0 ;}
@@ -509,16 +509,16 @@
     p = new T[4*nu*nv] ;
     if(!fin.read((char*)p,sizeof(T)*4*nu*nv)) { delete []type ; return 0 ;}
     p2 = p ;
-    offset.resize(nu,nv) ;
+    this->offset.resize(nu,nv) ;
     for(int i=0;i<nu;i++)
       for(int j=0;j<nv;j++){
-	offset(i,j).x() = *(p++) ;
-	offset(i,j).y() = *(p++) ;
-	offset(i,j).z() = *(p++) ;
-	offset(i,j).w() = *(p++) ;
+	this->offset(i,j).x() = *(p++) ;
+	this->offset(i,j).y() = *(p++) ;
+	this->offset(i,j).z() = *(p++) ;
+	this->offset(i,j).w() = *(p++) ;
       }
     delete []p2 ;    
-    --baseUpdateN ;
+    --(this->baseUpdateN) ;
     this->updateSurface() ;
   }
 
