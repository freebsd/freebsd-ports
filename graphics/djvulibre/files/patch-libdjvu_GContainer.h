--- libdjvu/GContainer.h.orig	Sat Nov  8 04:08:21 2003
+++ libdjvu/GContainer.h	Fri Oct  1 13:45:26 2004
@@ -786,9 +786,9 @@
 template<class TI> int
 GListImpl<TI>::operator==(const GListImpl<TI> &l2) const
 {
-  Node *p, *q;
+  ListNode<TI> *p, *q;
   for (p=head.next, q=l2.head.next; p && q; p=p->next, q=q->next )
-    if (p->data != q->data)
+    if (p->val != q->val)
       return 0;
   return p==0 && q==0;
 }
@@ -817,7 +817,7 @@
   // -- ACCESS
   /** Returns the number of elements in the list. */
   int size() const
-    { return nelem; }
+    { return this->nelem; }
   /** Returns the first position in the list. See \Ref{GPosition}. */
   GPosition firstpos() const
     { return GListImpl<TI>::firstpos(); }
@@ -846,7 +846,7 @@
   /** Tests whether a list is empty.  
       Returns a non zero value if the list contains no elements. */
   int isempty() const 
-    { return nelem==0; }
+    { return this->nelem==0; }
   /** Compares two lists. Returns a non zero value if and only if both lists
       contain the same elements (as tested by #TYPE::operator==(const TYPE&)#
       in the same order. */
@@ -1149,7 +1149,7 @@
 public:
   /** Returns the number of elements in the map. */
   int size() const
-    { return nelems; }
+    { return this->nelems; }
   /** Returns the first position in the map. */
   GPosition firstpos() const
     { return GMapImpl<KTYPE,TI>::firstpos(); }
@@ -1159,7 +1159,7 @@
   /** Tests whether the associative map is empty.  
       Returns a non zero value if and only if the map contains zero entries. */
   int isempty() const
-    { return nelems==0; }
+    { return this->nelems==0; }
   /** Searches an entry for key #key#.  If the map contains an entry whose key
       is equal to #key# according to #KTYPE::operator==(const KTYPE&)#, this
       function returns its position.  Otherwise it returns an invalid
@@ -1215,7 +1215,7 @@
   /* Old iterators. Do not use. */
 #if GCONTAINER_OLD_ITERATORS
   void first(GPosition &pos) const { pos = firstpos(); }
-  void last(GPosition &pos) const { pos = lastpos(); }
+  void last(GPosition &pos) const { pos = this->lastpos(); }
   const VTYPE *next(GPosition &pos) const 
     { if (!pos) return 0; const VTYPE *x=&((*this)[pos]); ++pos; return x; }
   VTYPE *next(GPosition &pos)
