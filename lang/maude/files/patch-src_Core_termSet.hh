In file included from symbol.cc:41:
In file included from ./term.hh:34:
../../src/Core/termSet.hh:35:15: error: ISO C++11 does not allow access declarations; use using declarations instead
  PointerSet::cardinality;
              ^

--- src/Core/termSet.hh.orig	2018-08-27 20:47:58 UTC
+++ src/Core/termSet.hh
@@ -32,8 +32,8 @@ class TermSet : private PointerSet
 public:
   void insert(Term* t);
   int term2Index(Term* t) const;
-  PointerSet::cardinality;
-  PointerSet::makeEmpty;
+  using PointerSet::cardinality;
+  using PointerSet::makeEmpty;
 
 private:
   unsigned int hash(void* pointer) const;
