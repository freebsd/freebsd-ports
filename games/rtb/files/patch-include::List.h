--- include/List.h.orig	Tue Sep 21 15:50:15 2004
+++ include/List.h	Tue Sep 21 17:22:32 2004
@@ -96,7 +96,7 @@
 inline T*
 ListIterator<T>::operator() () const
 {
-  if ( listp == NULL ) Error(true, "NULL pointer", "ListIterator::operator()");
+  if ( listp == NULL ) Error(true, (const String&)"NULL pointer", (const String&)"ListIterator::operator()");
 
   return listp->element;
 }
@@ -105,7 +105,7 @@
 inline const ListIterator<T>&
 ListIterator<T>::operator++ (int)
 {
-  if ( listp == NULL ) Error(true, "NULL pointer", "ListIterator::operator++");
+  if ( listp == NULL ) Error(true, (const String&)"NULL pointer", (const String&)"ListIterator::operator++");
   listp = listp->next;
   return *this;
 }
@@ -114,7 +114,7 @@
 inline const ListIterator<T>&
 ListIterator<T>::operator-- (int)
 {
-  if ( listp == NULL ) Error(true, "NULL pointer", "ListIterator::operator--");
+  if ( listp == NULL ) Error(true, (const String&)"NULL pointer", (const String&)"ListIterator::operator--");
   listp = listp->prev;
   return *this;
 }
