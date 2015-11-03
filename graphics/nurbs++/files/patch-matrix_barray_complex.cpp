--- matrix/barray_complex.cpp.orig	2008-02-13 22:26:03.000000000 +0100
+++ matrix/barray_complex.cpp	2008-02-13 22:26:20.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-ostream&
+template<> ostream&
 BasicArray<Complex>::print(ostream& os)  const{
   const int iend = size();
   
