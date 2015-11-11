--- matrix/vector.h.orig	Mon May 13 14:07:45 2002
+++ matrix/vector.h	Thu Nov 30 23:29:02 2006
@@ -69,7 +69,7 @@
   {
   public:
     int rows() const //!< a reference to the size of the vector
-      { return sze ;}
+      { return this->sze ;}
     Vector() : BasicArray<T>(1) {} //!< Basic constructor
     Vector(const int r) : BasicArray<T>(r) {}
     Vector(const Vector<T>& v) : BasicArray<T>(v) {}
@@ -90,7 +90,7 @@
     Vector<T> get(int i, int l);
     
     int minIndex() const ;
-    T minimum() const { return operator[](minIndex()) ; }  // returns the minimal value inside the vector
+    T minimum() const { return this->operator[](minIndex()) ; }  // returns the minimal value inside the vector
     
     void qSortStd() ;
     void qSort(int M=7) ; 
