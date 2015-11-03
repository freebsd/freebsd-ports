--- nurbs/nurbs.h.orig
+++ nurbs/nurbs.h
@@ -105,8 +105,8 @@
       
       // Basis functions
       T basisFun(T u, int i, int p=-1) const ;
-      void basisFuns(T u, int span, Vector<T>& N) const ;
-      void dersBasisFuns(int n,T u, int span, Matrix<T>& N) const;
+      void basisFuns(T u, int span, Vector<T>& N_) const ;
+      void dersBasisFuns(int n,T u, int span, Matrix<T>& N_) const;
       
       // Knot functions
       T minKnot() const //! the minimal value for the knot vector
