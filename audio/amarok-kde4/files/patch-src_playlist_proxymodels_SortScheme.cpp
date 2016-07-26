--- src/playlist/proxymodels/SortScheme.cpp.orig	2013-08-14 20:22:52 UTC
+++ src/playlist/proxymodels/SortScheme.cpp
@@ -123,13 +123,13 @@ SortScheme::trimToLevel( int lastLevel )
 SortScheme::const_iterator
 SortScheme::begin() const
 {
-    return QStack::begin();
+    return QStack<SortLevel>::begin();
 }
 
 SortScheme::const_iterator
 SortScheme::end() const
 {
-    return QStack::end();
+    return QStack<SortLevel>::end();
 }
 
 }   //namespace Playlist
