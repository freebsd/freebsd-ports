--- src/playlist/proxymodels/SortScheme.cpp.orig	2014-07-27 18:27:06.000000000 +0200
+++ src/playlist/proxymodels/SortScheme.cpp	2014-07-27 18:27:44.000000000 +0200
@@ -123,13 +123,13 @@
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
