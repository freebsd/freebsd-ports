--- src/NCollection/NCollection_Array1.hxx.orig	2023-12-04 15:53:08 UTC
+++ src/NCollection/NCollection_Array1.hxx
@@ -72,26 +72,10 @@ class NCollection_Array1 (public)
 
   using iterator = NCollection_IndexedIterator<std::random_access_iterator_tag, NCollection_Array1, value_type, false>;
   using const_iterator = NCollection_IndexedIterator<std::random_access_iterator_tag, NCollection_Array1, value_type, true>;
+  using Iterator = NCollection_Iterator<NCollection_Array1<TheItemType>>;
 
 public:
 
-  // Iterator class
-  class Iterator : public NCollection_Iterator<NCollection_Array1>
-  {
-  public:
-    using NCollection_Iterator<NCollection_Array1>::NCollection_Iterator;
-
-    const_reference Value() const
-    {
-      return *NCollection_Iterator<NCollection_Array1>::ValueIter();
-    }
-
-    reference ChangeValue()
-    {
-      return *NCollection_Iterator<NCollection_Array1>::ChangeValueIter();
-    }
-  };
-
   const_iterator begin() const
   {
     return const_iterator(*this);
@@ -150,7 +134,7 @@ class NCollection_Array1 (public)
     mySize(theUpper - theLower + 1),
     myPointer(nullptr),
     myIsOwner(false),
-    allocator_type(theAlloc)
+    myAllocator(theAlloc)
   {
     if (mySize == 0)
     {
