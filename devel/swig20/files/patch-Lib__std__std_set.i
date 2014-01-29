--- ./Lib/std/std_set.i.orig	2014-01-12 17:24:56.140822773 +1100
+++ ./Lib/std/std_set.i	2014-01-12 17:25:47.509154979 +1100
@@ -29,8 +29,14 @@
   reverse_iterator rbegin();
   reverse_iterator rend();
 
-  void erase(iterator pos);
-  void erase(iterator first, iterator last);
+// Backport C++11 support
+// Issue ID: https://github.com/swig/swig/issues/73
+// Commit: https://github.com/swig/swig/commit/92128eef445f75f674894e3f5d4e1fc2a1818957
+%extend {
+  // %extend wrapper used for differing definitions of these methods introduced in C++11
+  void erase(iterator pos) { $self->erase(pos); }
+  void erase(iterator first, iterator last) { $self->erase(first, last); }
+}
 
   iterator find(const key_type& x);
   iterator lower_bound(const key_type& x);
