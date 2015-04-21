--- imglib/imgops.h.orig	2009-06-09 22:32:20 UTC
+++ imglib/imgops.h
@@ -67,7 +67,8 @@ namespace iulib {
     }
 
     template<class T, class V>
-    void addscaled(colib::narray<T> &, colib::narray<T> &, V, int, int);
+    void addscaled(colib::narray<T> &dest, colib::narray<T> &src,
+                   V scale=1, int dx=0, int dy=0);
     template<class T>
     void tighten(colib::narray<T> &image);
     template<class T>
