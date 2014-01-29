--- ./Lib/std/std_map.i.orig	2014-01-12 17:22:34.464286699 +1100
+++ ./Lib/std/std_map.i	2014-01-12 17:25:54.847499215 +1100
@@ -12,9 +12,14 @@
   size_type count(const key_type& x) const;
 
 #ifdef SWIG_EXPORT_ITERATOR_METHODS
-//  iterator insert(iterator position, const value_type& x);
-  void erase(iterator position);
-  void erase(iterator first, iterator last);
+// Backport C++11 support
+// Issue ID: https://github.com/swig/swig/issues/73
+// Commit: https://github.com/swig/swig/commit/92128eef445f75f674894e3f5d4e1fc2a1818957
+%extend {
+  // %extend wrapper used for differing definitions of these methods introduced in C++11
+  void erase(iterator position) { $self->erase(position); }
+  void erase(iterator first, iterator last) { $self->erase(first, last); }
+}
 
   iterator find(const key_type& x);
   iterator lower_bound(const key_type& x);
