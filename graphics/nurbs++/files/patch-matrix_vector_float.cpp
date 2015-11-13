--- matrix/vector_float.cpp.orig	2008-02-13 22:15:33.000000000 +0100
+++ matrix/vector_float.cpp	2008-02-13 22:15:51.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  void Vector<float>::qSortStd(){
+  template<> void Vector<float>::qSortStd(){
     qsort((char*)memory(),n(),sizeof(float),compareFloat) ;
   }
 
