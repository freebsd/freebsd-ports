--- matrix/vector_int.cpp.orig	2008-02-13 22:13:23.000000000 +0100
+++ matrix/vector_int.cpp	2008-02-13 22:13:39.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  void Vector<int>::qSortStd(){
+  template<> void Vector<int>::qSortStd(){
     qsort((char*)memory(),n(),sizeof(int),compareInt) ;
   }
   
