--- nurbs/nurbsS.h.orig
+++ nurbs/nurbsS.h
@@ -99,8 +99,8 @@
   virtual HPoint_nD<T,N> operator()(T u, T v) const ;
 
   void basisFuns(T u, T v, int spanU, int spanV, Vector<T>& Nu, Vector<T>& Nv) const ;
-  void basisFunsU(T u, int span, Vector<T>& N) const ;
-  void basisFunsV(T u, int span, Vector<T>& N) const ;
+  void basisFunsU(T u, int span, Vector<T>& N_) const ;
+  void basisFunsV(T u, int span, Vector<T>& N_) const ;
   void dersBasisFuns(T u, T v, int dU, int dV,int uspan, int vspan,Matrix<T> & Niku, Matrix<T>& Njkv ) const ; 
 
   // Derivative functions
@@ -135,8 +135,8 @@
   int skinU(NurbsCurveArray<T,N>& ca, int degU);
   void sweep(const NurbsCurve<T,N>& t, const NurbsCurve<T,N>& C, const NurbsCurve<T,N>& Sv, int K,int useAy=0, int invAz=0) ;
   void sweep(const NurbsCurve<T,N>& t, const NurbsCurve<T,N>& C, int K,int useAy=0, int invAz=0) ;
-  void makeFromRevolution(const NurbsCurve<T,N>& profile, const Point_nD<T,N>& S, const Point_nD<T,N>& T, double theta) ;
-  void makeFromRevolution(const NurbsCurve<T,N>& profile, const Point_nD<T,N>& S, const Point_nD<T,N>& T) ;
+  void makeFromRevolution(const NurbsCurve<T,N>& profile, const Point_nD<T,N>& S, const Point_nD<T,N>& T_, double theta) ;
+  void makeFromRevolution(const NurbsCurve<T,N>& profile, const Point_nD<T,N>& S, const Point_nD<T,N>& T_) ;
   void makeFromRevolution(const NurbsCurve<T,N>& profile) ;
 
   void makeSphere(const Point_nD<T,N>& O, T r) ; 
