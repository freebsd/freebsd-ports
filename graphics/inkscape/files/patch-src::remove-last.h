--- src/remove-last.h.orig	Mon Apr 12 09:56:06 2004
+++ src/remove-last.h	Mon Apr 12 09:56:47 2004
@@ -2,6 +2,7 @@
 #define __REMOVE_LAST_H__
 
 #include <vector>
+#include <algorithm>
 #include <glib.h>
 
 template<class T>
@@ -9,7 +10,7 @@
 {
     using std::vector;
 
-    typename vector<T>::reverse_iterator i(find(seq.rbegin(), seq.rend(), elem));
+    typename vector<T>::reverse_iterator i(std::find(seq.rbegin(), seq.rend(), elem));
     g_assert( i != seq.rend() );
     typename vector<T>::iterator ii(&*i);
     seq.erase(ii);
