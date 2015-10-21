--- nurbs/hnurbsS_sp.h.orig
+++ nurbs/hnurbsS_sp.h
@@ -83,10 +83,10 @@
   T maxAtV(int i) const { return maxAtV_[i] ; }
 
   HPoint_nD<T,N> surfP(int i,int j) const 
-    { return hpointAt(maxAtU_[i],maxAtV_[j]); }
+    { return this->hpointAt(maxAtU_[i],maxAtV_[j]); }
 
   HPoint_nD<T,N> surfP(int i,int j, int lod) const
-    { return hpointAt(maxAtU_[i],maxAtV_[j],lod) ; }
+    { return this->hpointAt(maxAtU_[i],maxAtV_[j],lod) ; }
 
   void updateMaxUV() 
     { updateMaxU() ; updateMaxV() ; }
