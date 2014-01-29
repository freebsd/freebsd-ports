--- ./Lib/std/std_container.i.orig	2014-01-12 12:49:23.125903702 +1100
+++ ./Lib/std/std_container.i	2014-01-12 17:22:07.027709014 +1100
@@ -46,8 +46,14 @@
   void resize(size_type new_size);
   
   #ifdef SWIG_EXPORT_ITERATOR_METHODS
-  iterator erase(iterator pos);
-  iterator erase(iterator first, iterator last);
+// Backport C++11 support
+// Issue ID: https://github.com/swig/swig/issues/73
+// Commit: https://github.com/swig/swig/commit/92128eef445f75f674894e3f5d4e1fc2a1818957
+%extend {
+  // %extend wrapper used for differing definitions of these methods introduced in C++11
+  iterator erase(iterator pos) { return $self->erase(pos); }
+  iterator erase(iterator first, iterator last) { return $self->erase(first, last); }
+}
   #endif
   
 %enddef
@@ -68,8 +74,14 @@
   void resize(size_type new_size, const value_type& x);
   
   #ifdef SWIG_EXPORT_ITERATOR_METHODS
-  iterator insert(iterator pos, const value_type& x);
-  void insert(iterator pos, size_type n, const value_type& x);
+// Backport C++11 support
+// Issue ID: https://github.com/swig/swig/issues/73
+// Commit: https://github.com/swig/swig/commit/92128eef445f75f674894e3f5d4e1fc2a1818957
+%extend {
+  // %extend wrapper used for differing definitions of these methods introduced in C++11
+  iterator insert(iterator pos, const value_type& x) { return $self->insert(pos, x); }
+  void insert(iterator pos, size_type n, const value_type& x) { $self->insert(pos, n, x); }
+}
   #endif
   
 %enddef
@@ -89,8 +101,14 @@
   void resize(size_type new_size, value_type x);
   
   #ifdef SWIG_EXPORT_ITERATOR_METHODS
-  iterator insert(iterator pos, value_type x);
-  void insert(iterator pos, size_type n, value_type x);
+// Backport C++11 support
+// Issue ID: https://github.com/swig/swig/issues/73
+// Commit: https://github.com/swig/swig/commit/92128eef445f75f674894e3f5d4e1fc2a1818957
+%extend {
+  // %extend wrapper used for differing definitions of these methods introduced in C++11
+  iterator insert(iterator pos, value_type x) { return $self->insert(pos, x); }
+  void insert(iterator pos, size_type n, value_type x) { $self->insert(pos, n, x); }
+}
   #endif
   
 %enddef
