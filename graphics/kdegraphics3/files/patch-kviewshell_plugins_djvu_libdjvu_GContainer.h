--- kviewshell/plugins/djvu/libdjvu/GContainer.h.orig	2012-06-18 18:24:59.000000000 +0000
+++ kviewshell/plugins/djvu/libdjvu/GContainer.h
@@ -152,6 +152,86 @@ namespace DJVU {
 // Cf section 5.4.7 in november 1997 draft.
 #pragma warning( disable : 4243 )
 #endif
+// ------------------------------------------------------------
+// HASH FUNCTIONS
+// ------------------------------------------------------------
+
+
+/** @name Hash functions
+    These functions let you use template class \Ref{GMap} with the
+    corresponding elementary types. The returned hash code may be reduced to
+    an arbitrary range by computing its remainder modulo the upper bound of
+    the range.
+    @memo Hash functions for elementary types. */
+//@{
+
+/** Hashing function (unsigned int). */
+static inline unsigned int 
+hash(const unsigned int & x) 
+{ 
+  return x; 
+}
+
+/** Hashing function (int). */
+static inline unsigned int 
+hash(const int & x) 
+{ 
+  return (unsigned int)x;
+}
+
+/** Hashing function (long). */
+static inline unsigned int
+hash(const long & x) 
+{ 
+  return (unsigned int)x;
+}
+
+/** Hashing function (unsigned long). */
+static inline unsigned int
+hash(const unsigned long & x) 
+{ 
+  return (unsigned int)x;
+}
+
+/** Hashing function (void *). */
+static inline unsigned int 
+hash(void * const & x) 
+{ 
+  return (unsigned long) x; 
+}
+
+/** Hashing function (const void *). */
+static inline unsigned int 
+hash(const void * const & x) 
+{ 
+  return (unsigned long) x; 
+}
+
+/** Hashing function (float). */
+static inline unsigned int
+hash(const float & x) 
+{ 
+  // optimizer will get rid of unnecessary code  
+  unsigned int *addr = (unsigned int*)&x;
+  if (sizeof(float)<2*sizeof(unsigned int))
+    return addr[0];
+  else
+    return addr[0]^addr[1];
+}
+
+/** Hashing function (double). */
+static inline unsigned int
+hash(const double & x) 
+{ 
+  // optimizer will get rid of unnecessary code
+  unsigned int *addr = (unsigned int*)&x;
+  if (sizeof(double)<2*sizeof(unsigned int))
+    return addr[0];
+  else if (sizeof(double)<4*sizeof(unsigned int))
+    return addr[0]^addr[1];
+  else
+    return addr[0]^addr[1]^addr[2]^addr[3];    
+}
 
 
 // GPEnabled inhertenced removed again so the code works on more machines.
@@ -887,21 +967,21 @@ public:
   /** Inserts an element after the last element of the list. 
       The new element is initialized with a copy of argument #elt#. */
   void append(const TYPE &elt)
-    { GListImpl<TI>::append(newnode((const TI&)elt)); }
+    { GListImpl<TI>::append(this->newnode((const TI&)elt)); }
   /** Inserts an element before the first element of the list. 
       The new element is initialized with a copy of argument #elt#. */
   void prepend(const TYPE &elt)
-    { GListImpl<TI>::prepend(newnode((const TI&)elt)); }
+    { GListImpl<TI>::prepend(this->newnode((const TI&)elt)); }
   /** Inserts a new element after the list element at position #pos#.  When
       position #pos# is null the element is inserted at the beginning of the
       list.  The new element is initialized with a copy of #elt#. */
   void insert_after(GPosition pos, const TYPE &elt)
-    { GListImpl<TI>::insert_after(pos, newnode((const TI&)elt)); }
+    { GListImpl<TI>::insert_after(pos, this->newnode((const TI&)elt)); }
   /** Inserts a new element before the list element at position #pos#. When
       position #pos# is null the element is inserted at the end of the
       list. The new element is initialized with a copy of #elt#. */
   void insert_before(GPosition pos, const TYPE &elt)
-    { GListImpl<TI>::insert_before(pos, newnode((const TI&)elt)); }
+    { GListImpl<TI>::insert_before(pos, this->newnode((const TI&)elt)); }
   /** Inserts an element of another list into this list.  This function
       removes the element at position #frompos# in list #frompos#, inserts it
       in the current list before the element at position #pos#, and advances
@@ -1122,7 +1202,7 @@ GMapImpl<K,TI>::GMapImpl(const GCONT Tra
 template<class K, class TI> GCONT HNode *
 GMapImpl<K,TI>::get_or_create(const K &key)
 {
-  GCONT HNode *m = get(key);
+  GCONT HNode *m = this->get(key);
   if (m) return m;
   MNode *n = (MNode*) operator new (sizeof(MNode));
 #if GCONTAINER_ZERO_FILL
@@ -1131,7 +1211,7 @@ GMapImpl<K,TI>::get_or_create(const K &k
   new ((void*)&(n->key)) K  (key);
   new ((void*)&(n->val)) TI ();
   n->hashcode = hash((const K&)(n->key));
-  installnode(n);
+  this->installnode(n);
   return n;
 }
 
@@ -1197,13 +1277,13 @@ public:
       contains key #key#. This variant of #operator[]# is necessary when
       dealing with a #const GMAP<KTYPE,VTYPE>#. */
   const VTYPE& operator[](const KTYPE &key) const
-    { return (const VTYPE&)(((const typename GMapImpl<KTYPE,TI>::MNode*)(get_or_throw(key)))->val); }
+    { return (const VTYPE&)(((const typename GMapImpl<KTYPE,TI>::MNode*)(this->get_or_throw(key)))->val); }
   /** Returns a reference to the value of the map entry for key #key#.  This
       reference can be used for both reading (as "#a[n]#") and modifying (as
       "#a[n]=v#"). If there is no entry for key #key#, a new entry is created
       for that key with the null constructor #VTYPE::VTYPE()#. */
   VTYPE& operator[](const KTYPE &key)
-    { return (VTYPE&)(((typename GMapImpl<KTYPE,TI>::MNode*)(get_or_create(key)))->val); }
+    { return (VTYPE&)(((typename GMapImpl<KTYPE,TI>::MNode*)(this->get_or_create(key)))->val); }
   /** Destroys the map entry for position #pos#.  
       Nothing is done if position #pos# is not a valid position. */
   void del(GPosition &pos)
@@ -1266,86 +1346,6 @@ public:
 };
 
 
-// ------------------------------------------------------------
-// HASH FUNCTIONS
-// ------------------------------------------------------------
-
-
-/** @name Hash functions
-    These functions let you use template class \Ref{GMap} with the
-    corresponding elementary types. The returned hash code may be reduced to
-    an arbitrary range by computing its remainder modulo the upper bound of
-    the range.
-    @memo Hash functions for elementary types. */
-//@{
-
-/** Hashing function (unsigned int). */
-static inline unsigned int 
-hash(const unsigned int & x) 
-{ 
-  return x; 
-}
-
-/** Hashing function (int). */
-static inline unsigned int 
-hash(const int & x) 
-{ 
-  return (unsigned int)x;
-}
-
-/** Hashing function (long). */
-static inline unsigned int
-hash(const long & x) 
-{ 
-  return (unsigned int)x;
-}
-
-/** Hashing function (unsigned long). */
-static inline unsigned int
-hash(const unsigned long & x) 
-{ 
-  return (unsigned int)x;
-}
-
-/** Hashing function (void *). */
-static inline unsigned int 
-hash(void * const & x) 
-{ 
-  return (unsigned long) x; 
-}
-
-/** Hashing function (const void *). */
-static inline unsigned int 
-hash(const void * const & x) 
-{ 
-  return (unsigned long) x; 
-}
-
-/** Hashing function (float). */
-static inline unsigned int
-hash(const float & x) 
-{ 
-  // optimizer will get rid of unnecessary code  
-  unsigned int *addr = (unsigned int*)&x;
-  if (sizeof(float)<2*sizeof(unsigned int))
-    return addr[0];
-  else
-    return addr[0]^addr[1];
-}
-
-/** Hashing function (double). */
-static inline unsigned int
-hash(const double & x) 
-{ 
-  // optimizer will get rid of unnecessary code
-  unsigned int *addr = (unsigned int*)&x;
-  if (sizeof(double)<2*sizeof(unsigned int))
-    return addr[0];
-  else if (sizeof(double)<4*sizeof(unsigned int))
-    return addr[0]^addr[1];
-  else
-    return addr[0]^addr[1]^addr[2]^addr[3];    
-}
 
 
 //@}
