--- matrix/barray2d_uchar.cpp.orig	2008-02-13 22:18:33.000000000 +0100
+++ matrix/barray2d_uchar.cpp	2008-02-13 22:18:50.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-ostream& 
+template<> ostream& 
 Basic2DArray<unsigned char>::print(ostream& os) const
 {
   int i, j;
