--- libdjvu/Arrays.h.orig	Sat Nov  8 04:08:20 2003
+++ libdjvu/Arrays.h	Mon Sep 20 21:01:27 2004
@@ -708,21 +708,21 @@
 template <class TYPE> 
 TArray<TYPE>::TArray ()
 {
-   assign(new ArrayRep(sizeof(TYPE), destroy, init1,
+   this->assign(new ArrayRep(sizeof(TYPE), destroy, init1,
 		       init2, init2, insert));
 }
 
 template <class TYPE> 
 TArray<TYPE>::TArray(int hi)
 {
-   assign(new ArrayRep(sizeof(TYPE), destroy, init1,
+   this->assign(new ArrayRep(sizeof(TYPE), destroy, init1,
 		       init2, init2, insert, hi));
 }
 
 template <class TYPE> 
 TArray<TYPE>::TArray(int lo, int hi)
 {
-   assign(new ArrayRep(sizeof(TYPE), destroy, init1,
+   this->assign(new ArrayRep(sizeof(TYPE), destroy, init1,
 		       init2, init2, insert, lo, hi));
 }
 
@@ -854,21 +854,21 @@
 template <class TYPE> inline 
 DArray<TYPE>::DArray ()
 {
-   assign(new ArrayRep(sizeof(TYPE), destroy, init1,
+   this->assign(new ArrayRep(sizeof(TYPE), destroy, init1,
 		       init2, copy, insert));
 }
 
 template <class TYPE> inline 
 DArray<TYPE>::DArray(const int hi)
 {
-   assign(new ArrayRep(sizeof(TYPE), destroy, init1,
+   this->assign(new ArrayRep(sizeof(TYPE), destroy, init1,
 		       init2, copy, insert, hi));
 }
 
 template <class TYPE> inline 
 DArray<TYPE>::DArray(const int lo, const int hi)
 {
-   assign(new ArrayRep(sizeof(TYPE), destroy, init1,
+   this->assign(new ArrayRep(sizeof(TYPE), destroy, init1,
 		       init2, copy, insert, lo, hi));
 }
 
