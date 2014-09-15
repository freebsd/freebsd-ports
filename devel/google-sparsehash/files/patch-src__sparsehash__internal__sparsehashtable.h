--- ./src/sparsehash/internal/sparsehashtable.h.orig	2014-09-13 09:25:42.349531861 -0700
+++ ./src/sparsehash/internal/sparsehashtable.h	2014-09-13 09:27:25.632525344 -0700
@@ -165,7 +165,7 @@
  public:
   typedef sparse_hashtable_iterator<V,K,HF,ExK,SetK,EqK,A>       iterator;
   typedef sparse_hashtable_const_iterator<V,K,HF,ExK,SetK,EqK,A> const_iterator;
-  typedef typename sparsetable<V,DEFAULT_GROUP_SIZE,A>::nonempty_iterator
+  typedef typename sparsetable<V,DEFAULT_GROUP_SIZE,value_alloc_type>::nonempty_iterator
       st_iterator;
 
   typedef std::forward_iterator_tag iterator_category;  // very little defined!
@@ -217,7 +217,7 @@
  public:
   typedef sparse_hashtable_iterator<V,K,HF,ExK,SetK,EqK,A>       iterator;
   typedef sparse_hashtable_const_iterator<V,K,HF,ExK,SetK,EqK,A> const_iterator;
-  typedef typename sparsetable<V,DEFAULT_GROUP_SIZE,A>::const_nonempty_iterator
+  typedef typename sparsetable<V,DEFAULT_GROUP_SIZE,value_alloc_type>::const_nonempty_iterator
       st_iterator;
 
   typedef std::forward_iterator_tag iterator_category;  // very little defined!
@@ -271,7 +271,7 @@
 
  public:
   typedef sparse_hashtable_destructive_iterator<V,K,HF,ExK,SetK,EqK,A> iterator;
-  typedef typename sparsetable<V,DEFAULT_GROUP_SIZE,A>::destructive_iterator
+  typedef typename sparsetable<V,DEFAULT_GROUP_SIZE,value_alloc_type>::destructive_iterator
       st_iterator;
 
   typedef std::forward_iterator_tag iterator_category;  // very little defined!
