--- src/remove-last.h.orig	2011-07-08 20:25:09.468790000 +0200
+++ src/remove-last.h	2013-10-18 16:34:12.000000000 +0200
@@ -10,10 +10,9 @@
 {
     using std::vector;
 
-    typename vector<T>::reverse_iterator i(find(seq.rbegin(), seq.rend(), elem));
+    typename vector<T>::reverse_iterator i(std::find(seq.rbegin(), seq.rend(), elem));
     g_assert( i != seq.rend() );
-    typename vector<T>::iterator ii(&*i);
-    seq.erase(ii);
+    seq.erase(i.base());
 }
 
 
