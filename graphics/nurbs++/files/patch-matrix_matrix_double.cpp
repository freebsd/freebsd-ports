--- matrix/matrix_double.cpp.orig	2008-02-13 22:16:31.000000000 +0100
+++ matrix/matrix_double.cpp	2008-02-13 22:16:45.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
   
-  void Matrix<double>::qSort(){
+  template<> void Matrix<double>::qSort(){
     qsort((char*)m,rows()*cols(),sizeof(double),compareDouble) ;
   }
 
