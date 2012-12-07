--- modelgen/mg_.h.orig	2009-12-08 08:19:15.000000000 +0900
+++ modelgen/mg_.h	2012-10-14 00:54:09.000000000 +0900
@@ -108,6 +108,20 @@
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
@@ -200,20 +214,6 @@
   }
 };
 /*--------------------------------------------------------------------------*/
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
-};
-/*--------------------------------------------------------------------------*/
 class Key
   :public Base
 {
