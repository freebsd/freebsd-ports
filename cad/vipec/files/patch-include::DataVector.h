--- ../include/DataVector.h.orig	Tue Feb 13 06:23:19 2001
+++ ../include/DataVector.h	Fri Aug 20 21:56:44 2004
@@ -43,7 +43,6 @@
     uint getSize();
     void addPoint(TComplex value);
 
-private:
     DataVector(const DataVector& vector);
     
 
