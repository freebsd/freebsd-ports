--- include/BTree.h.orig	Tue Jul 16 14:23:25 2002
+++ include/BTree.h	Sat Jul 31 13:13:24 2004
@@ -236,7 +236,7 @@
 //  to the right and returns them.
 
 template <class Key, class Value>
-BTree<Key, Value>::Closure
+typename BTree<Key, Value>::Closure
 BTree<Key, Value>::Node::remove(unsigned j)
 {
     Key k = key[j];
@@ -348,7 +348,7 @@
 }
 
 template <class Key, class Value>
-BTree<Key, Value>::Closure
+typename BTree<Key, Value>::Closure
 BTree<Key, Value>::Node::next(const Key& pred) const
 {
     if (!this)
@@ -404,7 +404,7 @@
 //  nodes as necessary on the way back.
 
 template <class Key, class Value>
-BTree<Key, Value>::Closure
+typename BTree<Key, Value>::Closure
 BTree<Key, Value>::insert(Node *p, const Key& key, const Value& value)
 {
     if (!p) return Closure(key, value, NULL);
@@ -499,7 +499,7 @@
 //  Returns UNDER if node p is too small afterward, OK otherwise.
 
 template <class Key, class Value>
-BTree<Key, Value>::Status
+typename BTree<Key, Value>::Status
 BTree<Key, Value>::underflow(Node *p, unsigned i)
 {
     assert(p);
@@ -557,7 +557,7 @@
 
 
 template <class Key, class Value>
-BTree<Key, Value>::Closure
+typename BTree<Key, Value>::Closure
 BTree<Key, Value>::remove_rightmost(Node *p)
 {
     int i = p->n;
@@ -587,7 +587,7 @@
 //  back up.
 
 template <class Key, class Value>
-BTree<Key, Value>::Status
+typename BTree<Key, Value>::Status
 BTree<Key, Value>::remove(Node *p, const Key& key)
 {
     if (!p)
