--- matrix/list.h.orig	Mon May 13 14:07:45 2002
+++ matrix/list.h	Fri Dec  1 00:21:47 2006
@@ -89,6 +89,7 @@
   int resetMode() const { return reset_mode ; }
   void setResetMode(ListResetMode a ) { reset_mode = a ; }
 
+  BasicList<T> const &by_ref() { return *this ; }
 protected:
   BasicNode<T> *first_,*last_ ;
   int n ;
