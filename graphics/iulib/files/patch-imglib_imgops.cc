--- imglib/imgops.cc.orig	2009-06-09 22:32:20 UTC
+++ imglib/imgops.cc
@@ -133,7 +133,7 @@ namespace iulib {
 
     template<class T,class V>
     void addscaled(narray<T> &dest,narray<T> &src,
-            V scale=1,int dx=0,int dy=0) {
+            V scale,int dx,int dy) {
         for (int i=0; i<dest.dim(0); i++)
             for (int j=0; j<dest.dim(1); j++)
                 dest.unsafe_at(i,j) += (T)(scale*xref(src,i+dx,j+dy));
