--- src/NCollection/NCollection_Iterator.hxx.orig	2023-12-04 15:53:08 UTC
+++ src/NCollection/NCollection_Iterator.hxx
@@ -94,6 +94,16 @@ class NCollection_Iterator (public)
     ++(myCur);
   }
 
+  const typename Container::const_reference Value() const
+  {
+    return *myCur;
+  }
+
+  const typename Container::reference ChangeValue()
+  {
+    return *myCur;
+  }
+
   bool operator==(const NCollection_Iterator& theOther) { return myLast == theOther.myLast && myCur == theOther.myCur; }
 
   bool operator!=(const NCollection_Iterator& theOther) { return myLast != theOther.myLast || myCur != theOther.myCur; }
