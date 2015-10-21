--- matrix/matrix_float.cpp.orig	2008-02-13 22:14:25.000000000 +0100
+++ matrix/matrix_float.cpp	2008-02-13 22:14:45.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
   
-  void Matrix<float>::qSort(){
+  template<> void Matrix<float>::qSort(){
     qsort((char*)m,rows()*cols(),sizeof(float),compareFloat) ;
   }
 
