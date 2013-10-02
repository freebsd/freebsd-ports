--- include/ptlib/array.h.orig	2009-01-11 22:53:14.000000000 +0000
+++ include/ptlib/array.h
@@ -523,7 +523,7 @@ template <class T> class PScalarArray :
       T t;
       stream >> t;
       if (!stream.fail())
-        SetAt(index, t);
+        this->SetAt(index, t);
     }
 };
 
@@ -1221,7 +1221,7 @@ class PBitArray : public PBYTEArray
      */
     PBitArray & operator+=(
       PINDEX index  ///< Position on the array to get value from.
-    ) { SetAt(index, PTrue); return *this; }
+    ) { this->SetAt(index, PTrue); return *this; }
 
     /**Set a bit to the array.
 
@@ -1230,7 +1230,7 @@ class PBitArray : public PBYTEArray
      */
     PBitArray & operator-=(
       PINDEX index  ///< Position on the array to get value from.
-    ) { SetAt(index, PFalse); return *this; }
+    ) { this->SetAt(index, PFalse); return *this; }
 
     /**Concatenate one array to the end of this array.
        This function will allocate a new array large enough for the existing
