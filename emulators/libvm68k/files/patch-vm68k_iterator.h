--- vm68k/iterator.h.orig	Tue Jul  3 20:43:58 2001
+++ vm68k/iterator.h	Fri Dec  3 18:09:53 2004
@@ -127,7 +127,7 @@
   /* Implementation of `class basic_uint16_iterator'.  */
 
   template <class T>
-  inline basic_uint16_iterator<T>::ref &
+  inline typename basic_uint16_iterator<T>::ref &
   basic_uint16_iterator<T>::ref::operator=(const uint16_type &value)
   {
     p[0] = value >> 8;
@@ -262,7 +262,7 @@
   }
 
   template <class T>
-  inline basic_uint16_iterator<T>::ref
+  inline typename basic_uint16_iterator<T>::ref
   basic_uint16_iterator<T>::operator[](ptrdiff_t n)
   {
     return *(*this + n);
@@ -287,7 +287,7 @@
   /* Implementation of `class basic_uint32_iterator'.  */
 
   template <class T>
-  inline basic_uint32_iterator<T>::ref &
+  inline typename basic_uint32_iterator<T>::ref &
   basic_uint32_iterator<T>::ref::operator=(const uint32_type &value)
   {
     p[0] = value >> 24;
@@ -425,7 +425,7 @@
   }
 
   template <class T>
-  inline basic_uint32_iterator<T>::ref
+  inline typename basic_uint32_iterator<T>::ref
   basic_uint32_iterator<T>::operator[](ptrdiff_t n)
   {
     return *(*this + n);
