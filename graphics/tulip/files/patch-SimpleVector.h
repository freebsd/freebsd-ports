--- library/tulip/include/tulip/SimpleVector.h.orig	Sat Nov 30 21:35:57 2002
+++ library/tulip/include/tulip/SimpleVector.h	Fri Oct 29 14:14:08 2004
@@ -24,7 +24,7 @@
   explicit SimpleVector(size_t s) { begin=0; resize(s); }
   void resize(size_t s) {
     middleP=beginP+s;
-    if (middle>endP || size()<capacity()/2)
+    if (this->middle>endP || size()<capacity()/2)
       doRealloc(size());
   }
   iterator begin() { return beginP; }
