--- matrix/cvector.h.orig	Mon May 13 14:07:45 2002
+++ matrix/cvector.h	Thu Nov 30 23:30:00 2006
@@ -54,10 +54,10 @@
     CVector(const BasicArray<T>& v) : Vector<T>(v), index(0)  {;}
     virtual ~CVector() {}
     
-    T& operator[](const int i) { return x[i%sze]; }
-    T  operator[](const int i) const   { return x[i%sze]; }
+    T& operator[](const int i) { return this->x[i%this->sze]; }
+    T  operator[](const int i) const   { return this->x[i%this->sze]; }
     
-    void put(T v) { x[index] = v ; index = (index+1)%sze; }
+    void put(T v) { this->x[index] = v ; index = (index+1)%this->sze; }
     
   protected:
     int index ;
