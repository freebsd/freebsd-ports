--- src/NCollection/NCollection_DynamicArray.hxx.orig	2023-12-04 15:53:08 UTC
+++ src/NCollection/NCollection_DynamicArray.hxx
@@ -77,25 +77,9 @@ class NCollection_DynamicArray (public)
 
   using iterator = NCollection_IndexedIterator<std::random_access_iterator_tag, NCollection_DynamicArray, value_type, false>;
   using const_iterator = NCollection_IndexedIterator<std::random_access_iterator_tag, NCollection_DynamicArray, value_type, true>;
+  using Iterator = NCollection_Iterator<NCollection_DynamicArray<TheItemType>>;
 
 public:
-
-  // Iterator class
-  class Iterator : public NCollection_Iterator<NCollection_DynamicArray>
-  {
-  public:
-    using NCollection_Iterator<NCollection_DynamicArray>::NCollection_Iterator;
-
-    const_reference Value() const
-    {
-      return *NCollection_Iterator<NCollection_DynamicArray>::ValueIter();
-    }
-
-    reference ChangeValue()
-    {
-      return *NCollection_Iterator<NCollection_DynamicArray>::ChangeValueIter();
-    }
-  };
 
   const_iterator begin() const
   {
