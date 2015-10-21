--- nurbs/nurbs_sp.h.orig	Fri May 17 11:24:21 2002
+++ nurbs/nurbs_sp.h	Fri Dec  1 00:45:10 2006
@@ -72,7 +72,7 @@
   int read(ifstream &fin) ;
 
   void modSurfCPby(int i, const HPoint_nD<T,N>& a) 
-    { P[i] +=  a / maxU[i] ;  }
+    { this->P[i] +=  a / maxU[i] ;  }
   void modSurfCP(int i, const HPoint_nD<T,N>& a) 
     { modSurfCPby(i,a-surfP(i)) ;  }
 
@@ -84,7 +84,7 @@
     { return maxAt_[i] ; }
 
   HPoint_nD<T,N> surfP(int i) const 
-    { return hpointAt(maxAt_[i]) ; }
+    { return this->hpointAt(maxAt_[i]) ; }
 
   void updateMaxU() ;
 
