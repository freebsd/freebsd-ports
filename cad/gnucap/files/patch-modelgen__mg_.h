--- modelgen/mg_.h.orig	2013-04-24 03:24:21 UTC
+++ modelgen/mg_.h
@@ -108,6 +108,20 @@ class List_Base (public)
   size_t	 size()const	 {return _list.size();}
 };
 /*--------------------------------------------------------------------------*/
+class C_Comment
+  :public Base
+{
+public:
+  void parse(CS& f);
+};
+/*--------------------------------------------------------------------------*/
+class Cxx_Comment
+  :public Base
+{
+public:
+  void parse(CS& f);
+};
+/*--------------------------------------------------------------------------*/
 /* A "Collection" differs from a "List" in how it is parsed.
  * Each parse of a "Collection" created one more object and stores
  * it in the Collection.  The size of the Collection therefore grows by 1.
@@ -198,20 +212,6 @@ class Collection (public)
       f << (**i);
     }
   }
-};
-/*--------------------------------------------------------------------------*/
-class C_Comment
-  :public Base
-{
-public:
-  void parse(CS& f);
-};
-/*--------------------------------------------------------------------------*/
-class Cxx_Comment
-  :public Base
-{
-public:
-  void parse(CS& f);
 };
 /*--------------------------------------------------------------------------*/
 class Key
