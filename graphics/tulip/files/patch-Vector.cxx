--- library/tulip-geo/include/tulip/cxx/Vector.cxx.orig	Wed Apr  2 01:30:26 2003
+++ library/tulip-geo/include/tulip/cxx/Vector.cxx	Fri Oct 29 14:14:08 2004
@@ -1,15 +1,17 @@
+//#include <iostream>
+
 #define VECTORTLP tlp::geo::Vector<Obj,SIZE>
 
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::operator*=(const Obj &scalaire) {
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]*=scalaire;
+    this->array[i]*=scalaire;
   return (*this);
 }
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::operator*=(const VECTORTLP &vecto) {
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]*=vecto[i];
+    this->array[i]*=vecto[i];
   return (*this);
 }
 
@@ -17,14 +19,14 @@
 VECTORTLP & VECTORTLP::operator/=(const Obj &scalaire) {
   assert(scalaire!=0);
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]/=scalaire;
+    this->array[i]/=scalaire;
   return (*this);
 }
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::operator/=(const VECTORTLP &vecto) {
   for (unsigned int i=0;i<SIZE;++i) {
     assert(vecto[i]!=0);
-    array[i]/=vecto[i];
+    this->array[i]/=vecto[i];
   }
   return (*this);
 }
@@ -32,26 +34,26 @@
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::operator+=(const Obj &scalaire) {
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]+=scalaire;
+    this->array[i]+=scalaire;
   return (*this);
 }
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::operator+=(const VECTORTLP &vecto) {
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]+=vecto[i];
+    this->array[i]+=vecto[i];
   return (*this);
 }
 
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::operator-=(const Obj &scalaire) {
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]-=scalaire;
+    this->array[i]-=scalaire;
   return (*this);
 }
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::operator-=(const VECTORTLP &vecto) {
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]-=vecto[i];
+    this->array[i]-=vecto[i];
   return (*this);
 }
 
@@ -96,13 +98,13 @@
   VECTORTLP result;
   switch(SIZE){
   case 3:  
-    result[0]=array[1]*v[2]-array[2]*v[1];
-    result[1]=array[2]*v[0]-array[0]*v[2];
-    result[2]=array[0]*v[1]-array[1]*v[0];
+    result[0]=this->array[1]*v[2]-this->array[2]*v[1];
+    result[1]=this->array[2]*v[0]-this->array[0]*v[2];
+    result[2]=this->array[0]*v[1]-this->array[1]*v[0];
     return result;
     break;
   default :
-    std::cerr << "cross product not implemented for dimension :" << SIZE << endl;
+    std::cerr << "cross product not implemented for dimension :" << SIZE << std::endl;
     break;
   }
 }
@@ -110,14 +112,14 @@
 template <typename Obj,unsigned int SIZE>
 bool VECTORTLP::operator!=(const VECTORTLP &vecto) const {
   for (unsigned int i=0;i<SIZE;++i)
-    if (array[i]!=vecto[i]) return true;
+    if (this->array[i]!=vecto[i]) return true;
   return false;
 }
 
 template <typename Obj,unsigned int SIZE>
 bool VECTORTLP::operator==(const VECTORTLP &vecto) const {
   for (unsigned int i=0;i<SIZE;++i)
-    if (array[i]!=vecto[i]) return false;
+    if (this->array[i]!=vecto[i]) return false;
   return true;
 }
 
@@ -126,16 +128,16 @@
 template <typename Obj,unsigned int SIZE>
 Obj VECTORTLP::dotProduct(const VECTORTLP &v) const{
   assert (SIZE>0);
-  Obj tmpO= array[0] * v[0];
+  Obj tmpO= this->array[0] * v[0];
   for (unsigned int i=1;i<SIZE;++i)
-    tmpO+= array[i] * v[i];
+    tmpO+= this->array[i] * v[i];
   return tmpO;
 }
 
 template <typename Obj,unsigned int SIZE>
 VECTORTLP & VECTORTLP::fill(const Obj& scalaire) {
   for (unsigned int i=0;i<SIZE;++i)
-    array[i]=scalaire;
+    this->array[i]=scalaire;
   return (*this);
 }
 
@@ -143,17 +145,17 @@
 Obj  VECTORTLP::norm() const{
   switch(SIZE){
   case 1:  
-    return array[0];
+    return this->array[0];
   case 2:
-    return sqrt(array[0]*array[0]+array[1]*array[1]);
+    return sqrt(this->array[0]*this->array[0]+this->array[1]*this->array[1]);
     break;
   case 3:
-    return sqrt(array[0]*array[0]+array[1]*array[1]+array[2]*array[2]);
+    return sqrt(this->array[0]*this->array[0]+this->array[1]*this->array[1]+this->array[2]*this->array[2]);
     break;
   default :
     Obj tmp=0;
     for (unsigned int i=0;i<SIZE;++i)
-      tmp+=array[i]*array[i];
+      tmp+=this->array[i]*this->array[i];
     return(sqrt(tmp));
     break;
   }
@@ -165,15 +167,15 @@
   case 1:  
     return 0;
   case 2:
-    return sqrt((array[0]-c.array[0])*(array[0]-c.array[0])+(array[1]-c.array[1])*(array[1]-c.array[1]));
+    return sqrt((this->array[0]-c.array[0])*(this->array[0]-c.array[0])+(this->array[1]-c.array[1])*(this->array[1]-c.array[1]));
     break;
   case 3:
-    return sqrt((array[0]-c.array[0])*(array[0]-c.array[0])+(array[1]-c.array[1])*(array[1]-c.array[1])+(array[2]-c.array[2])*(array[2]-c.array[2]));
+    return sqrt((this->array[0]-c.array[0])*(this->array[0]-c.array[0])+(this->array[1]-c.array[1])*(this->array[1]-c.array[1])+(this->array[2]-c.array[2])*(this->array[2]-c.array[2]));
     break;
   default :
     Obj tmp=0;
     for (unsigned int i=0;i<SIZE;++i)
-      tmp+=(array[i]-c.array[i])*(array[i]-c.array[i]);
+      tmp+=(this->array[i]-c.array[i])*(this->array[i]-c.array[i]);
     return(sqrt(tmp));
     break;
   }
