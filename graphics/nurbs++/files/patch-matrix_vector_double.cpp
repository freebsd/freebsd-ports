--- matrix/vector_double.cpp.orig	2008-02-13 22:17:22.000000000 +0100
+++ matrix/vector_double.cpp	2008-02-13 22:17:40.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  void Vector<double>::qSortStd(){
+  template<> void Vector<double>::qSortStd(){
     qsort((char*)memory(),n(),sizeof(float),compareDouble) ;
   }
   
