--- ./platform/emulator/libfd/pel_internal.hh.orig	Mon Jan 13 14:21:11 2003
+++ ./platform/emulator/libfd/pel_internal.hh	Sat Sep  3 18:46:08 2005
@@ -9,8 +9,8 @@
  *    Organization or Person (Year(s))
  *
  *  Last change:
- *    $Date: 2003/01/13 19:21:11 $ by $Author: bruni $
- *    $Revision: 1.7 $
+ *    $Date: 2005/01/30 10:40:51 $ by $Author: glynn $
+ *    $Revision: 1.7.10.1 $
  *
  *  This file is part of Mozart, an implementation
  *  of Oz 3:
@@ -88,14 +88,14 @@
 class EnlargeableArrayWithBase : public M {
 private:
   virtual void _gCollect(void) {
-    T * new_array = (T *) alloc(_size * sizeof(T));
+    T * new_array = (T *) this->alloc(_size * sizeof(T));
     for (int i = _size; i--; ) {
       new_array[i] = _array[i];
     }
     _array = new_array;
   }
   virtual void _sClone(void) {
-    T * new_array = (T *) alloc(_size * sizeof(T));
+    T * new_array = (T *) this->alloc(_size * sizeof(T));
     for (int i = _size; i--; ) {
       new_array[i] = _array[i];
     }
@@ -107,7 +107,7 @@
   //
   T * realloc(T * old, int old_n, int new_n) {
     if (old_n < new_n) {
-      T * _new = (T *) alloc(new_n * sizeof(T));
+      T * _new = (T *) this->alloc(new_n * sizeof(T));
       T * _old = old;
       for (int i = old_n; i--; ) {
 	_new[i] = _old[i];
@@ -131,7 +131,7 @@
   }
   //
   EnlargeableArrayWithBase(int s) : _size(s) {
-    _array = s > 0 ? (T *) alloc(s * sizeof(T)) : (T *) NULL;
+    _array = s > 0 ? (T *) this->alloc(s * sizeof(T)) : (T *) NULL;
   }
   //
   T &operator [](int i) {
@@ -148,9 +148,9 @@
   //
 public:
   int push(T &d) {
-    _array[_high] = d;
+    this->_array[_high] = d;
     _high += 1;
-    request(_high);
+    this->request(_high);
     return _high-1;
   }
   //
@@ -168,13 +168,13 @@
   ResizeableArray(void) : EnlargeableArrayWithBase<T,M>() { }
   //
   void resize(int new_size) {
-    if (new_size > _size) {
-      _array = realloc(_array, _size, new_size);
-      _size = new_size;
+    if (new_size > this->_size) {
+      this->_array = realloc(this->_array, this->_size, new_size);
+      this->_size = new_size;
     }
   }
   void reset(void) {
-    _size = 0;
+    this->_size = 0;
   }
 };
 
